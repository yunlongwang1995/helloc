//
// Created by wangyunlong01 on 2022/4/12.
//

#include <iostream>
#include "zdb_rpc_impl.h"

namespace ZDB_NAMESPACE {

    Status ZObjectRPCDB::Open(const RPCDBOptions &options, const std::string& path, ZEngine **db) {
        /**
         * create rpc DB
         */

        std::cout << "create rpc db, path: " << path << std::endl;
        *db = new ZObjectRPCDB();
        return Status();
    }

    Status ZObjectRPCDB::CreateTable(const ZObjectTable &table) {
        /**
         * create a table
         */

        std::cout << "create a table, tableID: " << table.tableID << std::endl;
        this->tableManager.get()->tables.push_back(table);
        for (MetaListener* listener : this->tableManager.get()->listeners){
            listener->OnChange();
        }
        return Status();
    }

    Status ZObjectRPCDB::Write(const TableMetrics &tm) {
        /**
         * write data to rpc db
         */

        std::cout << "write data to rpc db, tableID: " << tm.tableID << std::endl;
        return Status();
    }

    Status ZObjectRPCDB::Read(const ZReadOptions &options) {
        /**
         * read data from rpc db
         */

        std::cout << "read data from rpc db" << std::endl;
        return Status();
    }
}