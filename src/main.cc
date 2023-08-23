#include <iostream>

#include "Singleton.h"

Singleton Singleton::instance;
LazySingleton *volatile LazySingleton::instance = nullptr;

int main()
{
    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();
    Singleton *s3 = Singleton::GetInstance();

    LazySingleton *l1 = LazySingleton::GetInstance();
    LazySingleton *l2 = LazySingleton::GetInstance();
    LazySingleton *l3 = LazySingleton::GetInstance();

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    return 0;
}
