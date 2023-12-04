//
// Created by wangyunlong01 on 2022/6/22.
//

/**
 * 创建即加锁，作用域结束自动析构并解锁，无需手工解锁
 * 不能中途解锁，必须等作用域结束才解锁
 * 不能复制
 */

#include <mutex>
#include <iostream>

using namespace std;

int main() {
    mutex mtx;
    {
        lock_guard<mutex> lockGuard(mtx);
        cout << "try_lock = " << mtx.try_lock() << endl;
    }

    cout << "try_lock = " << mtx.try_lock() << endl;
}