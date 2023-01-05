//
// Created by wangyunlong01 on 2022/6/22.
//

/**
 * lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。
 * 也就是说，使用该函数在指定范围内查找某个目标值时，最终查找到的不一定是和目标值相等的元素，
 * 还可能是比目标值大的元素。
 * @return
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool mycmp(int i, int j) {
  return i < j;
}

class Person {
public:
  Person(int age, string name) : age_(age), name_(name) {}

public:
  int age_;
  string name_;
};

bool comp2(Person l, Person r) {
  return l.age_ < r.age_;
}

int main() {

  // 在 [first, last) 区域内查找不小于 val 的元素
  vector<int> values = {1, 3, 5, 9, 10};
  auto p = lower_bound(values.begin(), values.end(), 5);
  cout << "p = " << *p << endl;

  vector<Person> values3;
  values3.emplace_back(Person(1, ""));
  values3.emplace_back(Person(3, ""));
  values3.emplace_back(Person(5, ""));
  values3.emplace_back(Person(7, ""));
  values3.emplace_back(Person(9, ""));
  values3.emplace_back(Person(11, ""));

  auto iter = lower_bound(values3.begin(), values3.end(), Person(4, "w"), comp2);
  if (iter == values3.end()) {
    cout << "not found..." << endl;
  } else {
    cout << iter.base()->age_ << endl;
  }
}
