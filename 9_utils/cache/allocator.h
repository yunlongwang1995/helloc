//
// Created by wangyunlong01 on 2022/6/29.
//

#ifndef HELLOC_ALLOCATOR_H
#define HELLOC_ALLOCATOR_H

#endif //HELLOC_ALLOCATOR_H

class Allocator {
public:
    virtual ~Allocator() {}
    virtual char* Allocate(int bytes) = 0;
    virtual char* AllocateAligned(int bytes) = 0;

    virtual int BlockSize() const = 0;
};

class Arena : public Allocator {

};