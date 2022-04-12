//
// Created by wangyunlong01 on 2022/4/12.
//
#pragma once

#ifndef HELLO_ZDB_LOCAL_IMPL_H
#define HELLO_ZDB_LOCAL_IMPL_H

#endif //HELLO_ZDB_LOCAL_IMPL_H

#include "../include/zdb/zengine.h"
#include "options.h"
#include "ztable_manager.h"

namespace ZDB_NAMESPACE {
    class ZObjectLocalDB : public ZEngine {
    public:
        ZObjectLocalDB() {};

        ~ZObjectLocalDB() {};

        static Status Open(const LocalDBOptions &options, const std::string &path, ZEngine **db);

        Status CreateTable(const ZObjectTable &table) override;

        Status Write(const TableMetrics &tm) override;

        Status Read(const ZReadOptions &options) override;

    public:
        std::unique_ptr<ZTableManager> tableManager;
    };
}
