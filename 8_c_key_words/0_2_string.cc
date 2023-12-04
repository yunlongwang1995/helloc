//
// Created by wangyunlong01 on 2022/6/27.
//

#include <cstring>
#include <iostream>

using namespace std;

/**
 * 地址测试
 */
void AddrTest();

void AssignmentTest();

/**
 * string 库常用方法测试
 */
void CommonMethodTest();

int main() {
  AddrTest();
  cout << "-------------------------" << endl;
  AssignmentTest();
  cout << "-------------------------" << endl;
  CommonMethodTest();
}

void AddrTest() {
  string s1 = "hello";
  cout << &s1 << endl;
  s1 += " world";
  cout << &s1 << endl;

  cout << s1[1] << endl;
  cout << &s1[1] << endl;
}

void AssignmentTest() {
  string s1 = "hello world ";
  string s2 = s1;
  cout << &s1 << endl;
  cout << &s2 << endl;

  const char *p = s2.c_str();
  cout << strlen(p) << endl;
}

void CommonMethodTest() {
  string val = "(())";
  // 1. c_str
  const char* p = val.c_str();
  cout << "c_str():\n" << *p << endl;
  p++;
  cout << *p << endl;
  p += 2;
  cout << (*p == 0) << endl;

  // 2. data()
  const char* p2 = val.data();
  cout << "data():\n" << *p2 << endl;
  p2++;
  cout << *p2 << endl;
  p2 += 2;
  cout << (*p2 == 0) << endl;

  // 3. find
  int idx = val.find(")*", 0);
  cout << "first: " << (idx) << endl;

  // 4. find_first_of
  cout << "find_first_of: " << val.find_first_of("()", 0) << endl;

  // 5. sub_str
  cout << "sub_str: " << (val.substr(0, 2) == "((") << endl;

  // 6. replace
  val = ".....";
  val.replace(3, 1, "Q");
  cout << val << endl;
}