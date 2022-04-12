//
// Created by wangyunlong01 on 2022/4/12.
//
#pragma once

#ifndef HELLO_ZTABLE_MANAGER_H
#define HELLO_ZTABLE_MANAGER_H

#endif //HELLO_ZTABLE_MANAGER_H

#include <vector>

#include "../include/zdb/ztable.h"
#include "../include/zdb/meta_listener.h"

namespace ZDB_NAMESPACE {
    class ZTableManager {
    public:
        ZTableManager(const ZOptions& options) : listeners(options.listeners){

        }

        ~ZTableManager(){

        }

        std::vector<ZObjectTable> tables;
        std::vector<std::shared_ptr<MetaListener>> listeners;
    };
}
