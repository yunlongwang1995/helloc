//
// Created by wangyunlong01 on 2022/6/27.
//

#include <iostream>
using namespace std;

int main() {
  int global_num = 5;
  {
    int global_num = 10;
    cout << global_num << endl;
    global_num = 15;
  }
  cout << global_num << endl;
}