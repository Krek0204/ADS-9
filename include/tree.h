// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>


int fact(int number) {
  int result = 1;
  for (int i = 1; i <= number; i++) result *= i;
  return result;
}

struct Node {
  char data;
  std::vector<Node*> heirs;
  explicit Node(char dat) : data(dat) {}
};

class PMTree {
 private:
  Node* root;
  int pCount;
  void buildTree(Node* root, std::vector<char>& symbols) {
    if (symbols.empty()) return;
    for (char c : symbols){
      root->heirs.push_back(new Node(c));
      std::vector<char> newR;
      for (char ch : symbols) {
        if (ch != c) newR.push_back(ch);
      }
      buildTree(root->heirs.back(), newR);
    }
  }

 public:
  explicit PMTree(const std::vector<char> alphabet) {
    if (alphabet.empty()) {
      root = nullptr;
      pCount = 0;
      return;
    }
    pCount = fact(alphabet.size());
    root = new Node(0);
    for (char cur : alphabet) {
      root->heirs.push_back(new Node(cur));
    }
    for (auto& it : root->heirs) {
      std::vector<char> ripo;
      for (char c : alphabet) {
        if (c != it->data) ripo.push_back(c);
      }
      buildTree(it, ripo);
    }
  }
  Node* getRoot() { return root;
  }
  int getPcount() { return pCount;
  }
};

std::vector<std::vector<char>> getAllPerms(PMTree &);
std::vector<char> getPerm1(PMTree&, int);
std::vector<char> getPerm2(PMTree&, int);

#endif  // INCLUDE_TREE_H_
