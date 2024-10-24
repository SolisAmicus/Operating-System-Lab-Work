/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_RESOURCE_H
#define _LINUX_RESOURCE_H

#include <linux/time64.h>
#include <linux/types.h>
#include <uapi/linux/resource.h>


struct task_struct;

void getrusage(struct task_struct *p, int who, struct rusage *ru);

struct ljj_rusage {
    struct timespec64 ru_utime;  // 用户态执行时间（秒+纳秒）
    struct timespec64 ru_stime;  // 系统态执行时间（秒+纳秒）
    long             ru_majflt;  // 页面错误次数（需要物理I/O）
    long             ru_minflt;  // 页面错误次数（无需物理I/O）
    long             ru_nswap;   // 进程换出次数
};

#endif
