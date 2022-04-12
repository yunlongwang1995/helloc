//
// Created by wangyunlong01 on 2022/4/6.
//
#pragma once

#include <iostream>
#include <cassert>
#include "include/zdb/zengine.h"

using namespace ZDB_NAMESPACE;

class MyListener : public MetaListener {
public:
    void OnChange() override {
        std::cout << "this is my listener" << std::endl;
    }
};

int main(int argc, char **argv) {

    ZEngine *db;
    std::string path = "/tmp/ztable";
    ZOptions options;
    options.isLocalDB = true;
    MyListener listener;
    options.listeners.push_back(std::make_shared<MyListener>(listener));

    // open db
    zdb::Status s = zdb::ZEngine::Open(options, path, &db);
    assert(s.ok());

    // create table
    zdb::ZObjectTable table;
    table.tableID = 53;
    db->CreateTable(table);

    // write
    TableMetrics tm;
    tm.tableID = 23;
    s = db->Write(tm);
    assert(s.ok());

    // read
    ZReadOptions zReadOptions;
    s = db->Read(zReadOptions);
    assert(s.ok());

    return 0;
}