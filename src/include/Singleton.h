#include <iostream>
#include <mutex>

// 饿汉模式
class Singleton
{
public:
    static Singleton *GetInstance();

private:
    static Singleton instance;
    Singleton(){};
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

class LazySingleton
{
public:
    static LazySingleton *GetInstance();

private:
    static LazySingleton *volatile instance;
    LazySingleton(){};
    LazySingleton(const Singleton &) = delete;
    LazySingleton &operator=(const LazySingleton &) = delete;

    std::mutex mtx;
};