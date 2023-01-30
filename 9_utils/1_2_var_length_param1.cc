#include <iostream>
#include <bitset>

void print() {} // 递归终止条件。这是必需的。

template<typename Type, typename... Types>
void print(const Type& arg, const Types& ... args) {
  std::cout << arg << std::endl;
  print(args...);
}

int main() {
  print(1, 3.1415, "Hello, world!", 1.618, true, std::bitset<16>(377), 40);
  return 0;
}