// Copyright 2022 NNTU-CS
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>

#include "tree.h"

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<char> current;
  std::vector<std::vector<char>> result;
  gettingAllPerms(tree.getRoot(), result, current);
  return result;
}

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

std::vector<char> getPerm1(PMTree& tree, int pos) {
  std::vector<std::vector<char>> perms = getAllPerms(tree);
  return perms[pos - 1];
}
