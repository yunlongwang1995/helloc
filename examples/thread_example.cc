//
// Created by wangyunlong01 on 2022/4/19.
//

#include <iostream>
#include <thread>
#include <unistd.h>

void printNum(int num) {
    for (int i=0; i<num; i++) {
        std::cout << i << std::endl;
    }

    sleep(2);
}

void printNum2() {
    int num = 100;
    for (int i=0; i<num; i++) {
        std::cout << i << std::endl;
    }

    sleep(1);
}

int main(){
    std::thread t1(printNum, 1000);
    std::thread t2(printNum, 2000);
    t1.join();
    t2.detach();
    std::cout << "main" << std::endl;
    std::cout << std::this_thread::get_id() << std::endl;
    std::this_thread::yield();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}