//
// Created by wangyunlong01 on 2022/4/11.
//
#pragma once

#include <iostream>
#include "../include/zdb/zengine.h"
#include "zdb_local_impl.h"
#include "zdb_rpc_impl.h"

namespace ZDB_NAMESPACE {
    Status ZEngine::Open(const ZOptions &options, const std::string &path, ZEngine **db) {
        if (options.isLocalDB) {
            LocalDBOptions opt;
            return ZObjectLocalDB::Open(opt, path, db);
        }

        RPCDBOptions opt;
        return ZObjectRPCDB::Open(opt, path, db);
    }
}

