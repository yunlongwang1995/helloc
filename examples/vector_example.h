//
// Created by wangyunlong01 on 2022/4/12.
//

#ifndef HELLO_VECTOR_EXAMPLE_H
#define HELLO_VECTOR_EXAMPLE_H

#endif //HELLO_VECTOR_EXAMPLE_H

#include <iostream>

class Animal {
public:
    virtual void sayHello() = 0;
};

class Dog : public Animal {
public:
    Dog(){}

    ~Dog(){}

    void sayHello() override {
        std::cout << "dog..." << std::endl;
    }
};

class Cat : public Animal {
public:

    Cat(){}

    ~Cat(){}
    void sayHello() override {
        std::cout << "cat..." << std::endl;
    }
};
