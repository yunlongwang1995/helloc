//
// Created by wangyunlong01 on 2022/6/29.
//

#ifndef HELLOC_STATUS_H
#define HELLOC_STATUS_H

#endif //HELLOC_STATUS_H

#include <cstring>
#include <string>

enum class StatusCode : char {
    OK = 0,
    OutOfMemory = 1,
    KeyError = 2,
    TypeError = 3,
    Invalid = 4,
    IOError = 5,
    CapacityError = 6,
    IndexError = 7,
    Cancelled = 8,
    UnknownError = 9,
    NotImplemented = 10,
    SerializationError = 11,
    RError = 13,
    NotFound = 14,
    // Gandiva range of errors
    CodeGenError = 40,
    ExpressionValidationError = 41,
    ExecutionError = 42,
    // Continue generic codes.
    AlreadyExists = 45,
    // 过期数据
    ExpiredError = 46
};

class Status {
public:
    Status() noexcept {
        state_ = NULL;
    }

    Status(StatusCode code, std::string msg) {
        state_ = new State;
        state_->code = code;
        state_->msg = msg;
    }

    Status(const Status &other) {
        if (other.state_ != NULL) {
            state_ = new State;
            state_->code = other.state_->code;
            state_->msg = other.state_->msg;
        }
    }

    Status &operator=(const Status &other) {
        if (other.state_ != NULL) {
            state_ = new State;
            state_->code = other.state_->code;
            state_->msg = other.state_->msg;
        }
        return *this;
    }

    ~Status() noexcept {
        // ARROW-2400: On certain compilers, splitting off the slow path improves
        // performance significantly.
        if ((state_ != NULL)) {
            DeleteState();
        }
    }

    void DeleteState() {
        delete state_;
        state_ = nullptr;
    }

    bool isOK() { return state_ == nullptr; };

    bool isExpired() { return state_ != nullptr && state_->code == StatusCode::ExpiredError; };

    std::string message() {
        if (state_ == NULL)
            return "";
        else
            return state_->msg;
    }

public:
    /// Return a success status
    static Status OK() { return Status(); }

    static Status NOT_FOUND(std::string msg) { return Status(StatusCode::NotFound, "NotFound: " + msg); }

    static Status ALREADY_EXISTS(std::string msg) { return Status(StatusCode::AlreadyExists, "AlreadyExists: " + msg); }

    static Status NOT_IMPLEMENTED(std::string msg) { return Status(StatusCode::NotImplemented, "NotImplemented : "+ msg); }

    static Status CapacityError(std::string msg) { return Status(StatusCode::CapacityError, "CapacityError : "+ msg); }

    static Status ExpiredError(std::string msg) { return Status(StatusCode::ExpiredError, "ExpiredError : "+ msg); }

    static Status NotFound(std::string msg) { return Status(StatusCode::NotFound, "NotFound : "+ msg); }

    static Status IOError(std::string msg) { return Status(StatusCode::IOError, "IOError : "+ msg); }

private:
    struct State {
        StatusCode code;
        std::string msg;
        //std::shared_ptr<StatusDetail> detail;
    };
    // OK status has a `NULL` state_.  Otherwise, `state_` points to
    // a `State` structure containing the error code and message(s)
    State* state_ = NULL;
};


