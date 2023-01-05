//
// Created by wangyunlong01 on 2022/7/1.
//

#include "../base.h"

int main() {
    std::shared_ptr<int> p = std::make_shared<int>(22);
    std::shared_ptr<int> q = std::make_shared<int>(14);

    std::atomic_exchange(&q, p);
    std::cout << *(p.get()) << std::endl;
    std::cout << *(q.get()) << std::endl;
    std::cout << p.use_count() << std::endl;
}
