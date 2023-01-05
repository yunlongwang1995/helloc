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

  if (argc == 3) {
    std::cout << "hello program crash!!!" << std::endl;
    std::cout << "sudo service apport stop" << std::endl;
    std::cout << "ulimit -c unlimited" << std::endl;
    std::cout << 100/(argc-3) << std::endl;
    return 0;
  }

  if (argc == 4) {
    std::cout << "hello memory leak!!!" << std::endl;
    std::cout << "valgrind --tool=memcheck --leak-check=full ./main hello 1 3" << std::endl;
    int* p = new int(88);
    std::cout << "my leak ptr: " << *p << std::endl;
    return 0;
  }

  std::cout << "hello c++ world" << std::endl;
}
