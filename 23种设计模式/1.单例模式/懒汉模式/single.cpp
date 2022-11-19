#include "single.h"
Singleton::Ptr Singleton::m_instance_ptr = nullptr;
std::mutex Singleton::m_mutex;
Singleton::Singleton()
{
    std::cout<<"constructor called!"<<std::endl;
}
Singleton::~Singleton()
{
    std::cout<<"destructor called!"<<std::endl;
}

 Singleton::Ptr Singleton::getInstance()
 {
        // "double checked lock"
        if(m_instance_ptr==nullptr)
        {
            std::lock_guard<std::mutex> lk(m_mutex);
            if(m_instance_ptr == nullptr)
            {
              m_instance_ptr = std::shared_ptr<Singleton>(new Singleton);
            }
        }
        return m_instance_ptr;
}


int main()
{
    Singleton::Ptr s1 = Singleton::getInstance();
    Singleton::Ptr s2 = Singleton::getInstance();
    Singleton::Ptr s3 = Singleton::getInstance();
    std::cout << s1 << ","<< s2 <<"," << s3 <<std::endl;
    return 0;

}