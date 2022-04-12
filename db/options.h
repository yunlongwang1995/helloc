//
// Created by wangyunlong01 on 2022/4/12.
//
#pragma once

#ifndef HELLO_OPTIONS_H
#define HELLO_OPTIONS_H

#endif //HELLO_OPTIONS_H

#include "../include/zdb/zdb_namespace.h"

namespace ZDB_NAMESPACE {
    class LocalDBOptions {
    public:
        LocalDBOptions(const ZOptions &opt) {

        }

        std::vector<std::shared_ptr<MetaListener *>> listeners;
    };

    class RPCDBOptions {
    public:
        RPCDBOptions(const ZOptions &opt) {

        }

        std::vector<std::shared_ptr<MetaListener *>> listeners;
    };
}
