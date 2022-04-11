//
// Created by wangyunlong01 on 2022/4/11.
//

#include <iostream>
#include "person.h"

Person::Person() {
    this->name = "jack";
    this->age = 18;
}

Person::~Person() {}

void Person::PrintInfo() {
    std::cout << this->name << std::endl;
    std::cout << this->age << std::endl;
}
