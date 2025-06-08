// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <algorithm>

struct Node {
  char data;
  std::vector<Node*> heirs;
  Node(char dat) : data(dat) {}
};

class PMTree {
 private:
   Node* root;
  int pCount;
  void buildTree(Node* root, std::vector<char> symbols){
     std::sort(symbols.begin(), symbols.end());
    for (int i = 0; i < symbols.size(); i++) {
       Node* temp = new Node(symbols[i]);
      root->heirs.push_back(temp);
       std::vector<char> next = symbols;
      next.erase(symbols.begin() + i);
       buildTree(temp, next);
    }
  };

  public:
  PMTree(const std::vector<char> alphabet) {
    root = new Node(0);
    buildTree(root, alphabet);
    pCount = 1;
    for (int i = 1; i <= alphabet.size(); i++) pCount *= i;
  }
  Node* getRoot() { return root;
  }
  int getPcount() { return pCount;
  }
};

std::vector<std::vector<char>> getAllPerms(PMTree &);
std::vector<char> getPerm1(PMTree&, int);

#endif  // INCLUDE_TREE_H_
