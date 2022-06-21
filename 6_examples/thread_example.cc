//
// Created by wangyunlong01 on 2022/4/19.
//

#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

void printNum(int num) {
    for (int i = 0; i < num; i++) {
        std::cout << i << std::endl;
    }

    sleep(2);
}

void printNum2() {
    int num = 100;
    for (int i = 0; i < num; i++) {
        std::cout << i << std::endl;
    }

    sleep(1);
}

void threadTest();

void lockTest();

void lock_guard_test();

int main() {
//    threadTest();
    lockTest();
}

void threadTest() {
    std::thread t1(printNum, 1000);
    std::thread t2(printNum, 2000);
    t1.join();
    t2.detach();
    std::cout << "main" << std::endl;
    std::cout << std::this_thread::get_id() << std::endl;
    std::this_thread::yield();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void lockTest() {
    std::mutex mutex;

    std::thread t([&]() {
        sleep(3);
        std::cout << "this is t" << std::endl;
        if (mutex.try_lock()) {
            std::cout << "ture" << std::endl;
            mutex.unlock();
        } else {
            std::cout << "false" << std::endl;
        }
    });

    sleep(4);
    mutex.lock();
    sleep(1);
    mutex.unlock();
    t.join();
}

void lock_guard_test() {
    std::mutex mutex;
    {
        std::lock_guard<std::mutex> lockGuard(mutex);
        // do something
    }
}