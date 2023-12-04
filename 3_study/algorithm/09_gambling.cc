//
// Created by wangyunlong01 on 2022/6/23.
//

#include<stdlib.h>
#include<time.h>
#include <iostream>

int NoRule(int round, int times) {
  int result = 0;
  int win = 0;
  int fail = 0;
  srand((int) time(0));

  for (int i = 0; i < round; ++i) {
    for (int j = 0; j < times; ++j) {
      if (rand() % 2 == 0) {
        ++win;
        result += 1;
      } else {
        ++fail;
        result -= 1;
      }
    }
  }
  std::cout << "\nNoRule::result: " << result << std::endl;
  std::cout << "win: " << win << ", fail: " << fail << std::endl;

  return result;
}

int Rule(int round, int times) {
  int result = 0;
  int win = 0;
  int fail = 0;
  srand((int) time(0));

  for (int i = 0; i < round; ++i) {
    int local_fail = 0;
    int flag = false;
    for (int j = 0; j < times; ++j) {
      if (rand() % 2 == 0) {
        ++win;
        if (flag) {
          result += 5;
        } else {
          result += 1;
        }
      } else {
        ++fail;
        if (flag) {
          result -= 5;
        } else {
          result -= 1;
        }

        ++local_fail;
        if (!flag && local_fail >= 3) {
          flag = true;
        }
      }
    }
  }
  std::cout << "\nRule::result: " << result << std::endl;
  std::cout << "win: " << win << ", fail: " << fail << std::endl;

  return result;
}

int main() {
  NoRule(100, 5);
  Rule(100, 5);
}