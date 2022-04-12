//
// Created by wangyunlong01 on 2022/4/11.
//

#ifndef HELLO_ZOPTIONS_H
#define HELLO_ZOPTIONS_H

#endif //HELLO_ZOPTIONS_H

#include <vector>
#include <shared_mutex>

#include "zdb_namespace.h"
#include "meta_listener.h"

namespace ZDB_NAMESPACE {
    class ZOptions {
    public:
        bool isLocalDB;
        std::vector<std::shared_ptr<MetaListener>> listeners;
    };

    class ZReadOptions {
    public:
        int tableID;
        long timestamp;
    };
}
