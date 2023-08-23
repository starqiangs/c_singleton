#include <iostream>
#include <mutex>

#include "Singleton.h"

Singleton Singleton::instance;
LazySingleton *volatile LazySingleton::instance = nullptr;
std::mutex LazySingleton::mtx;
std::mutex LazySingleton_up::mtx;

int main()
{
    Singleton *s1 = Singleton::GetInstance();
    Singleton *s2 = Singleton::GetInstance();
    Singleton *s3 = Singleton::GetInstance();

    LazySingleton *l1 = LazySingleton::GetInstance();
    LazySingleton *l2 = LazySingleton::GetInstance();
    LazySingleton *l3 = LazySingleton::GetInstance();

    LazySingleton_up *p1 = LazySingleton_up::GetInstance();
    LazySingleton_up *p2 = LazySingleton_up::GetInstance();
    LazySingleton_up *p3 = LazySingleton_up::GetInstance();

    std::cout << "Singleton addresses:" << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;

    std::cout << "LazySingleton addresses:" << std::endl;
    std::cout << "l1: " << l1 << std::endl;
    std::cout << "l2: " << l2 << std::endl;
    std::cout << "l3: " << l3 << std::endl;

    std::cout << "LazySingleton up addresses:" << std::endl;
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    std::cout << "p3: " << p3 << std::endl;

    return 0;
}
