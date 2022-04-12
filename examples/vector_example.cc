//
// Created by wangyunlong01 on 2022/4/12.
//
#include <iostream>
#include <vector>
#include <shared_mutex>
#include "vector_example.h"

int main(int argc, char **argv) {

    std::vector<Animal*> animals;
    Dog* dog = new Dog();
    animals.emplace_back(dog);
    Animal* cat = new Cat();
    animals.emplace_back(cat);

    for (auto animal : animals) {
        animal->sayHello();
    }
    std::cout << "hello world" << std::endl;

    // ******************

    std::vector<std::shared_ptr<Animal>> s_animals;
    Dog dog1;
    s_animals.push_back(std::make_shared<Dog>(dog1));
    for (auto animal : s_animals) {
        animal->sayHello();
    }
}
