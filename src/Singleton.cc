#include "Singleton.h"

Singleton *Singleton::GetInstance()
{
    return &instance;
}

LazySingleton *LazySingleton::GetInstance()
{
    if (instance == nullptr)
    {
        std::lock_guard<std::mutex> lock_guard(instance->mtx);
        if (instance == nullptr)
        {
            instance = new LazySingleton();
        }
    }
    return instance;
}

LazySingleton_up *LazySingleton_up::GetInstance()
{
    // 函数局部变量的初始化 在汇编指令上已经自动添加线程互斥指令了 线程是安全的
    static LazySingleton_up instance;
    return &instance;
}
