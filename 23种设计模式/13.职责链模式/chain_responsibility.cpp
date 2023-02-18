#include "chain_responsibility.h"

int main()
{
    std::shared_ptr<Manager> manager = std::make_shared<CommonManager>("经理");
    std::shared_ptr<Manager> major = std::make_shared<Majordomo>("总监");
    std::shared_ptr<Manager> generalManager = std::make_shared<GeneralManager>("总经理");
    //设置上级
    manager->SetSuperior(major);
    major->SetSuperior(generalManager);

    std::cout << "员工申请请假结果：" << std::endl;
    Request request;
    request.requestType = "请假";
    request.number = 1;
    request.requestContent = "小菜申请请假1天";
    manager->RequestApplications(request);

    std::cout << std::endl << "员工申请请假结果：" << std::endl;
    request.requestType = "请假";
    request.number = 4;
    request.requestContent = "小菜申请请假4天";
    manager->RequestApplications(request);

    std::cout << std::endl << "员工申请加薪结果：" << std::endl;
    request.requestType = "加薪";
    request.number = 400;
    request.requestContent = "小菜申请加薪400";
    manager->RequestApplications(request);

    std::cout << std::endl << "员工申请加薪结果：" << std::endl;
    request.requestType = "加薪";
    request.number = 1000;
    request.requestContent = "小菜申请加薪1000";
    manager->RequestApplications(request);



    return 0;
}