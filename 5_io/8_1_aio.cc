//
// Created by wangyunlong01 on 2022/6/28.
//

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/aio_abi.h>
#include <cstring>

int io_setup(unsigned nr, aio_context_t *ctxp) {
    return syscall(__NR_io_setup, nr, ctxp);
}

int io_submit(aio_context_t ctx, long nr, struct iocb **iocbpp) {
    return syscall(__NR_io_submit, ctx, nr, iocbpp);
}

int io_getevents(aio_context_t ctx, long min_nr, long max_nr,
                 struct io_event *events, struct timespec *timeout) {
    return syscall(__NR_io_getevents, ctx, min_nr, max_nr, events, timeout);
}

int io_destroy(aio_context_t ctx) {
    return syscall(__NR_io_destroy, ctx);
}

int main() {
    printf("now beginning....\n");
    aio_context_t *ctx = (aio_context_t *)malloc(sizeof(aio_context_t));
    memset(ctx, 0, sizeof(aio_context_t));  // It's necessary，这里一定要的
    printf("ctx size: %d \n", sizeof(aio_context_t));
    int errcode = io_setup(1024, ctx);

    long pageSize = sysconf(_SC_PAGESIZE);
    int fd = open("./direct.txt", O_CREAT | __O_DIRECT | O_WRONLY, S_IRWXU|S_IRWXG|S_IROTH);
    printf("open file direct.txt. fp: %d, pagesize: %d \n", fd, pageSize);

    char* buf = static_cast<char *>(aligned_alloc(pageSize, pageSize));
    strcpy(buf, "hello xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx abcdefg.");
    printf("memalign: %p, msg: %s\n", buf, buf);

    struct iocb *iocbpp = (struct iocb *)malloc(sizeof(struct iocb));
    memset(iocbpp, 0, sizeof(struct iocb));
    iocbpp[0].aio_buf   = (uint64_t)&buf[0];
    iocbpp[0].aio_reqprio    = 0;
    iocbpp[0].aio_fildes     = fd;
    iocbpp[0].aio_lio_opcode = IOCB_CMD_PWRITE;
    iocbpp[0].aio_offset = pageSize * 2;
    iocbpp[0].aio_nbytes = pageSize;

    {
        printf("iocb mem is: \n");
        char* tmp = (char*)iocbpp;
        for (int i = 0 ; i < sizeof(struct iocb); i++){
            printf("%u ", (uint8_t)tmp[i]);
        }
        printf("\n");

    }

    // // 提交异步操作，异步写磁盘
    int n = io_submit(*ctx, 1, &iocbpp);
    printf("==io_submit==: %d\n", n);

    struct io_event events[10];
    struct timespec timeout = {1, 100};
    // 检查写磁盘情况，类似于epoll_wait或select
    n = io_getevents(*ctx, 1, 10, events, &timeout);
    printf("io_getevents: %d \n", n);

    close(fd);
    io_destroy(*ctx);
}
