#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton
{

public:
    ~Singleton();
    static Singleton* getInstance();
    void showPrt();
    Singleton(const Singleton& other) = delete;
    void operator = (const Singleton& other) = delete;

private: 
    Singleton();
    static Singleton* singleton; 
};


#endif // ! 