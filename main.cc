//
// Created by wangyunlong01 on 2022/4/12.
//
#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "hello c++ world" << std::endl;

  auto param1 = argv[0];
  auto param2 = argv[1];

  std::cout << param1 << "\n" << param2 << std::endl;
}
