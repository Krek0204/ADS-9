// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <vector>
#include "tree.h"

void gettingAllPerms(Node* root, std::vector<std::vector<char>>& res,
                     std::vector<char> cur) {
  if (root->data != 0) cur.push_back(root->data);
  if (root->heirs.empty()) {
    if (!cur.empty()) res.push_back(cur);
  } else {
    for (auto it : root->heirs) gettingAllPerms(it, res, cur);
  }
  if (!cur.empty() && root->data != 0) cur.pop_back();
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<char> current;
  std::vector<std::vector<char>> result;
  gettingAllPerms(tree.getRoot(), result, current);
  return result;
}

bool Perm1DLC(Node* root, std::vector<char>& res, int& cur) {
  if (root->data != 0) res.push_back(root->data);
  if (root->heirs.empty()) {
    cur--;
    if (cur == 0) return true;
  } else {
    for (auto& it : root->heirs) {
      if (Perm1DLC(it, res, cur)) return true;
    }
  }
  res.pop_back();
  return false;
}


std::vector<char> getPerm1(PMTree& tree, int pos) { std::vector<char> result;
  if (pos < 1 || pos > tree.getPcount()) return {};
  int cur = pos;
  Node* rt = tree.getRoot();
  for (auto* it : rt->heirs) {
    if (Perm1DLC(rt, result, cur)) return result;
  }
  return {};
}

bool Perm2Finder(Node* root, std::vector<char>& res, int cnt) {
  if (root->heirs.empty()) return true;
  int currentP = fact(root->heirs.size() - 1);
  for (auto& it : root->heirs) {
    if (cnt < currentP) {
      res.push_back(it->data);
      return Perm2Finder(it, res, cnt);
    }
    cnt -= currentP;
  }
  return false;
}

std::vector<char> getPerm2(PMTree& tree, int pos) { 
  if (pos < 1 || pos > tree.getPcount()) return {};
  int cnt = pos - 1;
  std::vector<char> result;
  Node* rt = tree.getRoot();
  for (auto& it : rt->heirs) {
    int currentP = fact(rt->heirs.size() - 1);
    if (cnt < currentP) {
      result.push_back(it->data);
      if (Perm2Finder(it, result, cnt)) return result;
      break;
    }
    cnt -= currentP;
  }
  return result;
}
