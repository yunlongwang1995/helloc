//
// Created by wangyunlong01 on 2022/6/29.
//

#include "status.h"
#include "allocator.h"
#include <shared_mutex>

#ifndef HELLOC_CACHE_H
#define HELLOC_CACHE_H

#endif //HELLOC_CACHE_H

class Cache {
public:

    Cache(std::shared_ptr<Arena> arena = nullptr)
            : arena_(std::move(arena)) {}
    // No copying allowed
    Cache(const Cache&) = delete;
    Cache& operator=(const Cache&) = delete;

    struct Handle {};

    virtual const char* Name() const = 0;

    virtual Status Insert(const std::string& key, void* value, int charge, Handle** handle = nullptr) = 0;

    virtual Handle* Lookup(const std::string& key) = 0;

    virtual bool Release(Handle* handle) = 0;

    virtual void* Value(Handle* handle) = 0;

    virtual void Erase(const std::string& key) = 0;

    Arena* GetArena() {
        return arena_.get();
    }

private:
    std::shared_ptr<Arena> arena_;
};
