//
// Created by wangyunlong01 on 2022/4/13.
//

#include "common.h"
#include <shared_mutex>

using namespace std;

void funcPoint();

int main(int argc, char **argv) {
    funcPoint();

    shared_ptr<Animal> dog;

    {
        Dog *dog1 = new Dog("111");
        dog = make_shared<Dog>(*dog1);
    }

    dog->sayHello();
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

void funcPoint() {
    int (*fp)(int, int);
    fp = add;
    cout << fp(2, 1) << endl;

    fp = sub;
    cout << fp(2, 1) << endl;
}