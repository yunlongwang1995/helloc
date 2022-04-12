//
// Created by wangyunlong01 on 2022/4/6.
//
#pragma once

#include <iostream>
#include <cassert>
#include "include/zdb/zengine.h"

int main(int argc, char **argv) {
    std::cout << "hello world" << std::endl;

    zdb::ZEngine *db;
    std::string path = "/tmp/ztable";
    zdb::ZOptions options;
    options.isLocalDB = false;

    // open db
    zdb::Status s = zdb::ZEngine::Open(options, path, &db);
    assert(s.ok());

    // create table
    zdb::ZObjectTable table;
    table.tableID = 53;
    db->CreateTable(table);

    // write
    zdb::TableMetrics tm;
    tm.tableID = 23;
    s = db->Write(tm);
    assert(s.ok());

    // read
    zdb::ZReadOptions zReadOptions;
    s = db->Read(zReadOptions);
    assert(s.ok());

    return 0;
}