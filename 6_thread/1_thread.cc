//
// Created by wangyunlong01 on 2022/4/19.
//

#include <iostream>
#include <thread>

using namespace std;

void printNum(int num) {
    cout << "threadID: "<< this_thread::get_id() << ", num: " << num << endl;
    this_thread::yield();   // 让出时间片
    this_thread::sleep_for(std::chrono::seconds(1));  // Sleep 1s
}

int main() {
    thread t1(printNum, 1000);
    thread t2(printNum, 2000);
    t1.join();        // 主线程等待
    t2.detach();      // 与主县城分离

    cout << "main thread：" << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::seconds(2));
}