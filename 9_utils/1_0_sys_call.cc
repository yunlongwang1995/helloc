//
// Created by wangyunlong01 on 2022/6/22.
//

#include <iostream>
#include <stdlib.h>

int main() {
  int ret = system("ls");
  std::cout << "ret = " << ret << std::endl;
}