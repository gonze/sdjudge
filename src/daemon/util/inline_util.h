//
// Created by zhangyutong926 on 10/25/16.
//

#ifndef OJ_DAEMON_UTIL_H
#define OJ_DAEMON_UTIL_H

template<typename B, typename T>
T *FromOffset(B *base, T B:: *offset) {
    unsigned char *baseInter = (unsigned char *) base;
    int offsetValue = reinterpret_cast<int>(*(void **)(&offset));
    baseInter += offsetValue;
    return reinterpret_cast<T *>(baseInter);
}

#endif //OJ_DAEMON_UTIL_H
