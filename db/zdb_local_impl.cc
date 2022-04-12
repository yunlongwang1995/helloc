//
// Created by wangyunlong01 on 2022/4/12.
//

#include <iostream>
#include "zdb_local_impl.h"

namespace ZDB_NAMESPACE {

    ZObjectLocalDB::ZObjectLocalDB(const ZOptions &zOptions, const LocalDBOptions &options) : zOptions(zOptions),
                                                                                              options(options) {
        this->tableManager = std::make_unique<ZTableManager>(zOptions);
    }

    ZObjectLocalDB::~ZObjectLocalDB() {

    }

    Status ZObjectLocalDB::Open(const ZOptions &zOptions, const LocalDBOptions &options, const std::string &path,
                                ZEngine **db) {
        /**
         * create local DB
         */

        std::cout << "create local db, path: " << path << std::endl;
        *db = new ZObjectLocalDB(zOptions, options);
        return Status();
    }

    Status ZObjectLocalDB::CreateTable(const ZObjectTable &table) {
        /**
         * create a table
         */

        std::cout << "create a table, tableID: " << table.tableID << std::endl;
        this->tableManager.get()->tables.push_back(table);
        for (auto listener: this->tableManager.get()->listeners) {
            MetaListener* l = reinterpret_cast<MetaListener*>(listener.get());
            l->OnChange();
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