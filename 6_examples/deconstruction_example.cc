//
// Created by wangyunlong01 on 2022/4/13.
//
#include <iostream>
#include "common.h"

using namespace std;

void t1(Dog *dog) {
    Dog dog2("bajie");
    dog = &dog2;
    printf("%p\n", dog);
}

int main(int argc, char **argv) {

    Dog *dog;
    t1(dog);
    printf("%p\n", dog);
    cout << dog->name << endl;
}