//
// Created by wangyunlong01 on 2022/6/22.
//
#include <iostream>
#include "common.h"
using namespace std;

int main() {
    // 左值引用
    int num = 1;
    int& age = num;
    num = 3;
    cout << age << endl;

    // 右值引用
    int&& seq = 6;
    Dog dog = Dog("bajie");
    Dog&& dog1 = Dog("laozhu");
    dog1.sayHello();
}