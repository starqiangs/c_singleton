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
