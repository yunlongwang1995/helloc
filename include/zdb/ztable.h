//
// Created by wangyunlong01 on 2022/4/11.
//
#pragma once

#ifndef HELLO_ZTABLE_H
#define HELLO_ZTABLE_H

#endif //HELLO_ZTABLE_H

#include "zdb_namespace.h"

namespace ZDB_NAMESPACE {

    struct ZObjectTable {
        int tableID;
        std::string tableName;
        int valueType;
        int belongFamilyID;
        long atLocalTS;
    };


    struct TableMetrics {
        int tableID;
        long timestamp;
        bool valid;
        void *value;
    };
}