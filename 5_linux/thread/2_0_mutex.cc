//
// Created by wangyunlong01 on 2022/6/22.
//

/**
 * lock
 * try_lock: 不会阻塞
 * unlock
 */

#include <mutex>
#include <iostream>
#include <thread>
using namespace std;

class AtomicObj {
public:
    void AddAge(int n) {
        mtx.lock();
        age += n;
        mtx.unlock();

        mtx.try_lock();
    }

    void Lock() {
        mtx.lock();
    }

    bool TryLock() {
        return mtx.try_lock();
    }

    void Unlock() {
        mtx.unlock();
    }

private:
    int age;
    mutex mtx;
};

void AsyncFun(AtomicObj* obj) {
    cout << "async thread try_lock = " << obj->TryLock() << endl;
}

int main() {
    AtomicObj obj;
    obj.Lock();
    cout << "try_lock = " << obj.TryLock() << endl;
    cout << "try_lock = " << obj.TryLock() << endl;
    obj.Unlock();

    thread t1(AsyncFun, &obj);
    t1.join();
}