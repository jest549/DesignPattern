#include "single.h"
#include <iostream>
Singleton* Singleton::singleton = new Singleton;
Singleton::Singleton()
{
    std::cout << "Singleton constructor called"<< std::endl;
}
Singleton* Singleton::getInstance()
{
    return singleton;
}
void Singleton::showPrt()
{
    std::cout << this << std::endl;
}
Singleton::~Singleton()
{
    std::cout<<"Singleton destructor called!"<<std::endl;
}



int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    Singleton* s3 = Singleton::getInstance();
    std::cout << s1 << ","<< s2 <<"," << s3 <<std::endl; //s1、s2和s3 地址一样
    return 0;

}