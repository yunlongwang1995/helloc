#include <iostream>
#include <vector>

using namespace std;

int RemoveNum(vector<int>& list, int target) {
  int offset = 0;
  int idx = 0;
  for (auto num: list) {
    if (num != target) {
      list[idx - offset] = num;
    } else {
      ++offset;
    }

    ++idx;
  }

  return list.size() - offset;
}

int main() {
  vector<int> list = {1, 2, 2, 5, 2, 3};
  cout << "num: " << RemoveNum(list, 2) << endl;
  for (auto n: list) {
    cout << n << "  ";
  }
}