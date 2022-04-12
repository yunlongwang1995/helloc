//
// Created by wangyunlong01 on 2022/4/12.
//

#ifndef HELLO_DEFAULT_LISTENER_H
#define HELLO_DEFAULT_LISTENER_H

#endif //HELLO_DEFAULT_LISTENER_H

#include <iostream>
#include "../include/zdb/meta_listener.h"

namespace ZDB_NAMESPACE {
    class DefaultListener : public MetaListener {
    public:
        void OnChange() override {
            std::cout << "this a default listener" << std::endl;
        }
    };
}