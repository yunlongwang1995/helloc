//
// Created by wangyunlong01 on 2022/7/1.
//

#ifndef HELLOC_COMMON_H
#define HELLOC_COMMON_H

#endif //HELLOC_COMMON_H

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sayHello() = 0;
};

class Dog : public Animal {
public:
    void sayHello() override {
        cout << "wangwang...: " << this->name << endl;
    }

    Dog(string name) {
        this->name = name;
        cout << "dog construction: " << this->name << endl;
    }

    ~Dog() {
        cout << "dog deconstruction :" << this->name << endl;
    }

public:
    string name;
};