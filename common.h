//
// Created by wangyunlong01 on 2022/7/1.
//

#pragma once

#ifndef HELLOC_COMMON_H
#define HELLOC_COMMON_H

#endif //HELLOC_COMMON_H

#include <iostream>

#include <array>
#include <vector>
#include <queue>
#include <unordered_map>

#include <algorithm>

using namespace std;

class Animal {
public:
  virtual void sayHello() = 0;
};

class Dog : public Animal {
public:
  void sayHello() override {
    cout << "wangwang...: " << this->name << endl;
  }

  Dog(string name) {
    this->name = name;
    cout << "dog construction: " << this->name << endl;
  }

  ~Dog() {
    cout << "dog deconstruction :" << this->name << endl;
  }

public:
  string name;
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct LNode {
  int val;
  LNode* next;
};
