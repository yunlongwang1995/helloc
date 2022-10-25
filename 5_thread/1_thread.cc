//
// Created by wangyunlong01 on 2022/4/19.
//

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void printNum(int num) {
  this_thread::sleep_for(std::chrono::seconds(num));  // Sleep 1s
  cout << "threadID: " << this_thread::get_id() << ", num: " << num << endl;
  this_thread::yield();   // 让出时间片
}

int main() {
  std::thread threads[2];
  threads[0] = thread(printNum, 1);
  threads[1] = thread(printNum, 5);

  threads[0].join();        // 主线程等待
  threads[1].detach();      // 与主线程分离

  cout << "main thread：" << this_thread::get_id() << endl;
  this_thread::sleep_for(chrono::seconds(2));
}