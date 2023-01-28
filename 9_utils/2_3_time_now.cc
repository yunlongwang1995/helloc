//
// Created by wangyunlong01 on 2022/6/17.
//

#include <ctime>
#include <iostream>

int main() {
  time_t now = time(0);
  std::cout << now << std::endl;

  auto c = ctime(&now);
  std::cout << c << std::endl;
}
