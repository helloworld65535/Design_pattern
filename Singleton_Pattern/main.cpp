#include <iostream>
#define 线程非安全版本

#ifdef 双检查锁reorder安全版本
#include <atomic>
#include <mutex>
#endif
/* 我们将创建一个 SingleObject 类。
SingleObject 类有它的私有构造函数和本身的一个静态实例。
SingleObject 类提供了一个静态方法，供外界获取它的静态实例。
SingletonPatternDemo 类使用 SingleObject 类来获取 SingleObject 对象。 */

/* 步骤 1
创建一个 Singleton  类。 */
class Singleton
{
private:
#ifdef 双检查锁reorder安全版本
    static std::atomic<Singleton *> instance;
    static std::mutex mutex;
#else
    static Singleton *instance;
#endif
    Singleton()
    {
        std::cout << "构造" << std::endl;
    }

    Singleton(const Singleton &);

public:
    ~Singleton()
    {
        std::cout << "析构" << std::endl;
    }
    static Singleton *getInstance();
    void showMessage()
    {
        std::cout << "Hello, World!" << std::endl;
    }
};
#ifndef 双检查锁reorder安全版本
Singleton *Singleton::instance = nullptr;
#endif

int main()
{
    /* 步骤 2
    从 singleton 类获取唯一的对象。 */
    Singleton *singleton = Singleton::getInstance();
    singleton->showMessage();
    delete singleton;

    return 0;
}

#ifdef 线程非安全版本
Singleton *Singleton::getInstance()
{
    if (instance == nullptr)
        instance = new Singleton();
    return instance;
}
#endif
#ifdef 线程安全版本但锁的代价过高
Singleton *Singleton::getInstance()
{
    Lock lock;
    if (instance == nullptr)
        instance = new Singleton();
    return instance;
}
#endif
#ifdef 双检查锁但是由于内存读写reorder不安全
Singleton *Singleton::getInstance()
{
    if (instance == nullptr)
    {
        Lock lock;
        if (instance == nullptr)
            instance = new Singleton();
    }
    return instance;
}
#endif
#ifdef 双检查锁reorder安全版本
std::atomic<Singleton *> Singleton::instance;
std::mutex Singleton::mutex;
Singleton *Singleton::getInstance()
{
    Singleton *temp = instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if (instance == nullptr)
    {
        std::lock_guard<std::mutex> lock(mutex);
        temp = instance.load(std::memory_order_relaxed);
        if (instance == nullptr)
        {
            instance = new Singleton();
            std::atomic_thread_fence(std::memory_order_release);
            instance.store(temp, std::memory_order_relaxed);
        }
    }
    return instance;
}
#endif