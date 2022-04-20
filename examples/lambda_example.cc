//
// Created by wangyunlong01 on 2022/4/20.
//
#include <iostream>

int cal(int (*f)(int, int), int, int);

int main() {

    // add
    std::cout << cal([](int a, int b) -> int {
        return a + b;
    }, 10, 20) << std::endl;

    // sub
    auto sub = [](int a, int b) ->int {
        return a-b;
    };
    std::cout << cal(sub, 10, 20) << std::endl;
}

int cal(int (*f)(int a, int b), int a, int b) {
    return f(a, b);
}

