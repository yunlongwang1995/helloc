//
// Created by wangyunlong01 on 2022/4/13.
//

#include "../common.h"
#include <memory>

shared_ptr<Animal> ret(bool empty) {
    if (empty) {
        return nullptr;
    }

    return make_shared<Dog>("333");
}

int main(int argc, char **argv) {
    shared_ptr<Animal> dog;
    dog = ret(true);

//    {
//        dog = make_shared<Dog>("222");
//    }

    dog->sayHello();
}