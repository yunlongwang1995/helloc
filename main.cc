//
// Created by wangyunlong01 on 2022/4/12.
//
#include <iostream>

/**
 * 入门用例
 * @param argc 　　参数个数 3
 * @param argv 　　参数列表 ./main hello 123
 * @return
 */
int main(int argc, char* argv[]) {
  std::cout << "hello c++ world" << std::endl;

  auto param1 = argv[0];
  auto param2 = argv[1];

  std::cout <<" argc: " << argc << std::endl;
  std::cout <<" param1: " << param1 << std::endl;
  std::cout <<" param2: " << param2 << std::endl;
}
