//
// Created by wangyunlong01 on 2022/4/12.
//
#pragma once

#ifndef HELLO_ZDB_RPC_IMPL_H
#define HELLO_ZDB_RPC_IMPL_H

#endif //HELLO_ZDB_RPC_IMPL_H

#include "../include/zdb/zengine.h"
#include "ztable_manager.h"
#include "options.h"

namespace ZDB_NAMESPACE {
    class ZObjectRPCDB : public ZEngine {
    public:
        ZObjectRPCDB(const ZOptions& zOptions, const RPCDBOptions& options);

        ~ZObjectRPCDB();

        static Status Open(const ZOptions& zOptions, const RPCDBOptions &options, const std::string &path, ZEngine **db);

        Status CreateTable(const ZObjectTable &table) override;

        Status Write(const TableMetrics &tm) override;

        Status Read(const ZReadOptions &options) override;

    public:
        const ZOptions& zOptions;
        const RPCDBOptions& rpcOptions;
        std::unique_ptr<ZTableManager> tableManager;
    };
};

