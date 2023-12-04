//
// Created by wangyunlong01 on 2022/6/22.
//
#include <atomic>
#include <iostream>
using namespace std;

int main() {
  atomic<int> num;
  num.fetch_add(50);
  int res = num.fetch_add(50);
  cout << res << endl;
}