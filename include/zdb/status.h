//
// Created by wangyunlong01 on 2022/4/11.
//
#pragma once

#ifndef HELLO_STATUS_H
#define HELLO_STATUS_H

#endif //HELLO_STATUS_H

#include "zdb_namespace.h"

namespace ZDB_NAMESPACE {
    class Status {
    public:
        Status() : code_(kOk) {

        }

        ~Status() {

        }

        enum Code : unsigned char {
            kOk = 0,
            kNotFound = 1,
            kCorruption = 2,
            kNotSupported = 3,
            kInvalidArgument = 4,
            kIOError = 5,
            kMergeInProgress = 6,
            kIncomplete = 7,
            kShutdownInProgress = 8,
            kTimedOut = 9,
            kAborted = 10,
            kBusy = 11,
            kExpired = 12,
            kTryAgain = 13,
            kCompactionTooLarge = 14,
            kColumnFamilyDropped = 15,
            kMaxCode
        };

        bool ok() const {
            return this->code_ == kOk;
        }

    protected:
        Code code_;
    };
}