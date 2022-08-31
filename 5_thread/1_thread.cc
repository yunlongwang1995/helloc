//
// Created by wangyunlong01 on 2022/4/19.
//

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void printNum(int num) {
  cout << "threadID: " << this_thread::get_id() << ", num: " << num << endl;
  this_thread::yield();   // 让出时间片
  this_thread::sleep_for(std::chrono::seconds(1));  // Sleep 1s
}

int main() {
  std::thread threads[2];
//  std::vector<std::thread> threads;
  {
    thread(printNum, 1000).detach();
  }
//  threads[0].join();        // 主线程等待
//  threads[0].detach();      // 与主线程分离

  cout << "main thread：" << this_thread::get_id() << endl;
  this_thread::sleep_for(chrono::seconds(2));
}