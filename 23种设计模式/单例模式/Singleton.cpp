//Singleton.cpp
#include "Singleton.h"
#include <iostream>
using namespace std;
Singleton* Singleton::m_instance = NULL;
Singleton::Singleton()
{
    cout<<"Singleton...."<<endl;
}
Singleton* Singleton::Instance()
{
    if (m_instance == NULL)
    {
        m_instance = new Singleton();
    }
    return m_instance;
}