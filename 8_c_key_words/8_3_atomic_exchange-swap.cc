//
// Created by wangyunlong01 on 2022/7/1.
//

#include "../base.h"

/**
 * atomic_exchange
 *   第二个参数　给　第一个参数　赋值
 */
void AtomicExchangeTest() {
  shared_ptr<int> p = make_shared<int>(18);
  shared_ptr<int> q = make_shared<int>(28);
  shared_ptr<int> s = p;

  atomic_exchange(&p, q);
  cout << *(p.get()) << endl;
  cout << *(q.get()) << endl;
  cout << *(s.get()) << endl;
  cout << p.use_count() << endl;
  cout << s.use_count() << endl;
}

/**
 * 交换 a 与 b 的值（可能是值或地址）
 */
void SwapTest() {
  int a = 18;
  int b = 28;
  int* p = &a;
  int* q = &b;
  swap(p, q);
  cout << "*p = " << *p << endl;
  cout << "*q = " << *q << endl;
}

int main() {
  AtomicExchangeTest();
  cout << "--------------" << endl;
  SwapTest();
}
