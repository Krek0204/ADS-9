// Copyright 2022 NNTU-CS
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <vector>
#include <random>
#include "tree.h"


int main() {
  std::vector<char> alphabet;
  for (char ch = 'a'; ch <= 'j'; ch++) {
    alphabet.push_back(ch);
    unsigned int seed = time(0);
    std::cout << "Current size of alphabet is " << alphabet.size() << std::endl;
    int randompos = rand_r(&seed) % 26 + 1;
    PMTree tree(alphabet);


    auto start = std::chrono::steady_clock::now();
    auto res = getAllPerms(tree);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> result = end - start;
    std::cout << "Time for all perms is: " << result.count() << std::endl;


    start = std::chrono::steady_clock::now();
    auto perm1 = getPerm1(tree, randompos);
    end = std::chrono::steady_clock::now();
    result = end - start;
    std::cout << "Time for perms1 is: " << result.count() << std::endl;


    start = std::chrono::steady_clock::now();
    auto perm2 = getPerm2(tree, randompos);
    end = std::chrono::steady_clock::now();
    result = end - start;
    std::cout << "Time for perms2 is: " << result.count() << std::endl;
    std::cout << std::endl << std::endl;
  }
  return 0; }
