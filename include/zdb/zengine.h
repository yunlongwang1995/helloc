//
// Created by wangyunlong01 on 2022/4/11.
//
#pragma once

#ifndef HELLO_ZENGINE_H
#define HELLO_ZENGINE_H

#endif //HELLO_ZENGINE_H

#include <string>
#include "zdb_namespace.h"
#include "status.h"
#include "zoptions.h"
#include "ztable.h"

namespace ZDB_NAMESPACE {

    class ZEngine {
    public:
        /**
         * create a db instance
         * @param options
         * @param path
         * @param db
         * @return
         */
        static Status Open(const ZOptions &options, const std::string &path, ZEngine **db);

        /**
         * create a table
         * @param table
         * @return
         */
        virtual Status CreateTable(const ZObjectTable &table) = 0;

        /**
         * write data to a specified table
         * @param tm
         * @return
         */
        virtual Status Write(const TableMetrics &tm) = 0;

        /**
         * read data from specified table
         * @param options
         * @return
         */
        virtual Status Read(const ZReadOptions &options) = 0;
    };
}