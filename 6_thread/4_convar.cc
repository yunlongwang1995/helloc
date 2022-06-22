//
// Created by wangyunlong01 on 2022/6/22.
//

#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
using namespace std;

mutex mtx;
condition_variable cv;

int cargo = 0;
bool shipment_available() { return cargo != 0;}  // 可货运

void Consumer(int n) {
    for (int i=0; i<n; ++i) {
        unique_lock<mutex> uniqueLock(mtx);
        while (!shipment_available()) {
            // shipment_available == false 阻塞
            cv.wait(uniqueLock, shipment_available);
        }

        cout << "consumer num: " << i << endl;
        cargo = 0;
    }
}

int main() {
    const int num = 10;
    thread t1(Consumer, num);

    for (int i=0; i<num; ++i) {
        while (shipment_available()) {
            this_thread::yield();
        }

        unique_lock<mutex> uniqueLock(mtx);
        ++cargo;
        cv.notify_one();
    }

    t1.join();
}