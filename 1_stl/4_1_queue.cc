//
// Created by wangyunlong01 on 2022/6/21.
//

#include <queue>
#include <iostream>

int main() {
    std::queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    std::cout << queue.front() << std::endl;
    queue.pop();
    std::cout << queue.front() << std::endl;
}