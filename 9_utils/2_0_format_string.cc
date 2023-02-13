//
// Created by wangyunlong01 on 2022/6/17.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
  const int MAX_STRING_LENGTH = 10;
  char name[MAX_STRING_LENGTH];
  snprintf(name, MAX_STRING_LENGTH, "hell:%d", 12);
  cout << name << endl;
}

