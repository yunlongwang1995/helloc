#include <iostream>

int get_num_of_target(int n, int target) {
  int count = 0;
  while (n > 0) {
    if (n % 10 == target) {
      ++count;
    }
    n = n / 10;
  }

  return count;
}

int main(int argc, char* argv[]) {
  int n, cn;
  std::cin >> n >> cn;

  if (n < 1 || cn > 9 || cn < 0) {
    std::cout << -1 << std::endl;
    return 0;
  }

  int count = 0;
  for (int i = 1; i <= n; ++i) {
    count += get_num_of_target(i, cn);
  }

  std::cout << count << std::endl;
  return 0;
}