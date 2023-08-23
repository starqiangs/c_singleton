#include "Singleton.h"

Singleton *Singleton::GetInstance()
{
    return &instance;
}

LazySingleton *LazySingleton::GetInstance()
{
    if (instance == nullptr)
    {
        instance = new LazySingleton();
    }
    return instance;
}
