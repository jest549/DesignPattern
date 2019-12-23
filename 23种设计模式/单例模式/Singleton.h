//Singleton.h
#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <iostream>
using namespace std;
class Singleton
{
    public:
        static Singleton* Instance();
    protected:
        Singleton();
    private:
        static Singleton* m_instance;
};
#endif //~_SINGLETON_H_   /


