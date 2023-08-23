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

    static std::mutex mtx;
};


class LazySingleton_up
{
public:
    static LazySingleton_up *GetInstance();
private:
    LazySingleton_up(){};
    LazySingleton_up(const LazySingleton_up &) = delete;
    LazySingleton_up &operator=(const LazySingleton_up &) = delete;

    static std::mutex mtx;
};