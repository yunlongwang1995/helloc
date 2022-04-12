//
// Created by wangyunlong01 on 2022/4/12.
//

#include <iostream>
#include "zdb_local_impl.h"

namespace ZDB_NAMESPACE {

    Status ZObjectLocalDB::Open(const LocalDBOptions &options, const std::string& path, ZEngine **db) {
        /**
         * create local DB
         */

        std::cout << "create local db, path: " << path << std::endl;
        *db = new ZObjectLocalDB();
        return Status();
    }

    Status ZObjectLocalDB::CreateTable(const ZObjectTable &table) {
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

    Status ZObjectLocalDB::Write(const TableMetrics &tm) {
        /**
         * write data to local db
         */

        std::cout << "write data to local db, tableID: " << tm.tableID << std::endl;
        return Status();
    }

    Status ZObjectLocalDB::Read(const ZReadOptions &options) {
        /**
         * read data from local db
         */

        std::cout << "read data from local db" << std::endl;
        return Status();
    }
}