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
#include <queue>          // 优先队列（堆）
#include <stack>
#include <unordered_map>

#include <memory>

#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

class Animal {
public:
  virtual void sayHello() = 0;

  virtual ~Animal() {};
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

// 链表节点
struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 树节点
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

