#include <iostream>
#include "stdarg.h"

int sum(int count, ...) {
  if (count <= 0) {
    return 0;
  }
  int sum = 0;

  va_list arg_ptr;
  va_start(arg_ptr, count);
  for (int i = 0; i < count; ++i) {
    sum += va_arg(arg_ptr, int);
  }
  va_end(arg_ptr);
  return sum;
}

int main() {
  std::cout << sum(3, 22, 33, 44, 55, 66, 77, 88, 99) << std::endl;
}
