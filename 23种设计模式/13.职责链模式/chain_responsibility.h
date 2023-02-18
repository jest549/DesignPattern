#include <iostream>
using namespace std;
#include <memory>
//请求类
struct Request
{
    std::string requestType;//请求类型
    int            number;//该请求类型的数量
    std::string requestContent;//请求内容
};

//抽象经理类
class Manager
{
private:
    std::string name;
    std::shared_ptr<Manager> superior; //管理者的上级

public:
    Manager(const std::string& strName) : name(strName) {}

    void SetSuperior(std::shared_ptr<Manager> smartSuperior) //设置管理者的上级
    {
        superior = smartSuperior;
    }

    std::shared_ptr<Manager> GetSuperior() const
    {
        return superior;
    }

    const std::string& GetName() const
    {
        return name;
    }

    virtual void RequestApplications(const Request& request) = 0;
};

//经理   经理所能有的权限就是可批准下属两天内的假期
class CommonManager : public Manager
{
public:
    CommonManager(const std::string& strName) : Manager(strName) {} 
    virtual void RequestApplications(const Request& request)
    {
        if (request.requestType == "请假" && request.number <= 2)
        {
            std::cout << "" << GetName().c_str() << ":" << request.requestContent.c_str() << " 数量 " << request.number << " 被批准！" << std::endl;
        }
        else
        {
            std::shared_ptr<Manager> superior = GetSuperior();
            if (superior != NULL) //其余的申请都需转到上级
            {
                superior->RequestApplications(request);
            }
        }
    }
};

//总监类      总监所能有的权限就是可批准下属一周内的假期
class Majordomo : public Manager
{
public:
    Majordomo(const std::string& strName) : Manager(strName) {}
    virtual void RequestApplications(const Request& request)
    {
        if (request.requestType == "请假" && request.number <= 5)
        {
            std::cout << "" << GetName().c_str() << ":" << request.requestContent.c_str() << " 数量 " << request.number << " 被批准！" << std::endl;
        }
        else
        { 
            std::shared_ptr<Manager> superior = GetSuperior(); 
            if (superior != NULL) //其余的申请都需转到上级
            {
                superior->RequestApplications(request);
            }
        }
    }
};

//总经理类
class GeneralManager : public Manager
{
public:
    GeneralManager(const std::string& strName) : Manager(strName) {}
    virtual void RequestApplications(const Request& request)
    {
        if (request.requestType == "请假" ||
            (request.requestType == "加薪" && request.number <= 500))
        {
            std::cout << "" << GetName().c_str() << ":" << request.requestContent.c_str() << " 数量 " << request.number << " 被批准！" << std::endl;
        }
        else if (request.requestType == "加薪" && request.number > 500)
        {
            std::cout << "" << GetName().c_str() << ":" << request.requestContent.c_str() << " 数量 " << request.number << " 被拒绝！" << std::endl;
        }
        else
        {
            std::cout << "" << GetName().c_str() << ":" << request.requestContent.c_str() << " 数量 " << request.number << " 无法处理！" << std::endl;
        }
    }
};

