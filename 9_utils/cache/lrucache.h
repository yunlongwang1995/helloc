//
// Created by wangyunlong01 on 2022/6/29.
//

#ifndef HELLOC_LRUCACHE_H
#define HELLOC_LRUCACHE_H

#endif //HELLOC_LRUCACHE_H

#include "cache.h"
#include <unordered_map>

class LRUHandle : public Cache::Handle {
public:
    LRUHandle() : ref(0),
                  charge(0),
                  key(),
                  value(nullptr),
                  next(nullptr),
                  prev(nullptr){}

    bool HasRefs() const {
        return ref > 0;
    }

    void Ref() {
        ref++;
    }

public:
    std::string key;
    void *value;
    int ref;
    int charge;

    LRUHandle *next;
    LRUHandle *prev;
};


class ZLRUCache : public Cache {
public:
    const char *Name() const override {
        return "ZLRUCache";
    }

    ZLRUCache(int capacity) : capacity_(capacity) {
    }

    Status Insert(const std::string &key, void *value, int charge, Handle **handle) override {
        LRUHandle *item = new LRUHandle;
        item->key = key;
        item->value = value;
        item->ref = 1;
        item->charge = charge;

        return InsertItem(item, handle);
    }

    Handle *Lookup(const std::string &key) override {
        return nullptr;
    }

    bool Release(Handle *handle) override {
        return false;
    }

    void *Value(Handle *handle) override {
        return nullptr;
    }

    void Erase(const std::string &key) override {

    }

public:
    Status InsertItem(LRUHandle *item, Handle **handle) {
        std::lock_guard<std::mutex> lockGuard(mutex_);
        // 回收内存
        EvictFromLRU(item->charge);

        // 内存依旧不够
        if (item->charge + usage_ > capacity_) {
            delete item;
            return Status::CapacityError("cache is full");
        }

        //　内存足够
        auto old = table_.find(item->key);
        if (old != table_.end()) {
            // key exist

        } else {
            // key no exist
            table_.emplace(item->key, item);
            if (handle == nullptr) {
                LRUInsert(item);
            } else {
                *handle = reinterpret_cast<Cache::Handle *>(item);
            }
        }
    }

    // 从链表中淘汰数据，释放内存
    void EvictFromLRU(int charge) {
        while (charge + usage_ > capacity_) {
            // 回收工作

        }
    }

    //　放入淘汰链表中
    void LRUInsert(LRUHandle *e) {

    }

private:
    std::unordered_map<std::string, LRUHandle *> table_;
    LRUHandle lru_;
    const int capacity_;
    int usage_;

    std::mutex mutex_;
};