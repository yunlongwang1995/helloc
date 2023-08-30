#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include "../base.h"

sigjmp_buf jmp_env;

static void handle_alarm(int) {
  siglongjmp(jmp_env, 1);
}

int main() {
  int timeout = 6;
  int runtime = 5;

  log("timeout = %d, run time = %d", timeout, runtime);
  if (timeout) {
    // 注册一个信号处理函数
    signal(SIGALRM, handle_alarm);
    alarm(timeout);
    log("set timeout: %ds", timeout);
    if (sigsetjmp(jmp_env, 1)) {
      log("running timeout...");
      goto out;
    }
  }

  sleep(runtime);
  log("running...");

out:
  if (timeout) {
    // 取消先前设置的闹钟
    alarm(0);
    log("cancel timeout");
  }

  return 0;
}