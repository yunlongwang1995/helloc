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
        static Status Open(const ZOptions &options, const std::string &path, ZEngine **db);

        virtual Status Write(const TableMetrics &tm) = 0;

        virtual Status Read() = 0;
    };
}