//
// Created by wangyunlong01 on 2022/6/27.
//

#include <string>
#include <iostream>

using namespace std;

class StaticTest {
public:
  static StaticTest* GetInstance() {
    static StaticTest instance;
    return &instance;
  }

public:
  int flag;
};

void call() {
  static int times;
  times++;
  cout << times << endl;
}

int main() {
  StaticTest* inst = StaticTest::GetInstance();
  inst->flag = 10;
  cout << StaticTest::GetInstance()->flag << endl;

  inst->flag = 15;
  cout << StaticTest::GetInstance()->flag << endl;

  call();
  call();
  call();
  call();
  call();
}