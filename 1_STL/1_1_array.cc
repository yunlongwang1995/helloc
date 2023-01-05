//
// Created by wangyunlong01 on 2022/6/21.
//

#include <array>
#include <iostream>

int main() {
    // 初始化
    std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};
    std::cout << arr[9] << std::endl;

    std::cout<<"正向遍历： ";
    for (auto it=arr.begin(); it!=arr.end(); ++it) {
        std::cout<< *it << "  ";
        *it += 10;
    }
    std::cout<<std::endl;

    std::cout<<"反向遍历： ";
    for (auto it=arr.rbegin(); it!=arr.rend(); ++it) {
        std::cout<< *it << "  ";
    }
    std::cout<<std::endl;

    arr.fill(99);
    std::cout<<"正向常量遍历： ";
    for (auto it=arr.cbegin(); it!=arr.cend(); ++it) {
        std::cout<< *it << "  ";
    }
}
