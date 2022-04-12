//
// Created by wangyunlong01 on 2022/4/12.
//
#pragma once

#ifndef HELLO_META_LISTENER_H
#define HELLO_META_LISTENER_H

#endif //HELLO_META_LISTENER_H

#include "zdb_namespace.h"

namespace ZDB_NAMESPACE {
    class MetaListener {
    public:
        virtual void OnChange() = 0;
    };
}