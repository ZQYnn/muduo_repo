#pragma once

#include <unistd.h>
#include <sys/syscall.h>

namespace CurrentThread
{
    //  每个 线程都有自己的tid 
    extern __thread int t_cachedTid;

    void cacheTid();

    inline int tid()
    {
        if (__builtin_expect(t_cachedTid == 0, 0))
        {
            cacheTid();
        }
        return t_cachedTid;
    }
}