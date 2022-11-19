#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <iostream>
#include <memory> // shared_ptr
#include <mutex>  // mutex

class Singleton{
public:
    typedef std::shared_ptr<Singleton> Ptr;
    ~Singleton();
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Ptr getInstance();
private:
    Singleton();
    static Ptr m_instance_ptr;
    static std::mutex m_mutex;
};

#endif // ! 