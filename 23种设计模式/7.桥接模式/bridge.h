#ifndef  _BRIDGE_H_
#define _BRIDGE_H_
#include <iostream>
#include <string>
// 实现化角色：支付模式
class IPayMode {
public:
    virtual bool security(std::string Uid) = 0;
};

// 具体实现化角色：密码支付
class PayCypher : public IPayMode {
public:
    bool security(std::string uId) override {
        std::cout << "密码支付，风控校验环境安全" << std::endl;
        return true;
    }
};

// 具体实现化角色：人脸支付
class PayFaceMode : public IPayMode {
public:
    bool security(std::string uId) override {
        std::cout << "人脸支付，风控校验脸部识别" << std::endl;
        return true;
    }
};

// 具体实现化角色：指纹支付
class PayFingerprintMode : public IPayMode {
public:
    bool security(std::string uId) override {
        std::cout << "指纹支付，风控检验指纹信息" << std::endl;
        return true;
    }
};

// 抽象化角色：支付
class Pay {
public:
    Pay(IPayMode* payMode) {
        this->payMode = payMode;
    }

    virtual ~Pay() { delete payMode; }

    virtual std::string transfer(std::string uId, std::string tradeId, long long amount) = 0;

protected:
    IPayMode* payMode;
};

// 扩展抽象化角色： 微信支付
class WxPay : public Pay {
public:
    WxPay(IPayMode* payMode) : Pay(payMode) { }

    std::string transfer(std::string uId, std::string tradeId, long long amount) {
        std::cout << "模拟微信渠道支付划账开始，uId: " << uId << " tradeId: " 
             << tradeId << " amount: " << amount << std::endl;
        bool security = payMode->security(uId);
        if (!security) {
            std::cout << "模拟微信渠道支付划账拦截，uId: " << uId << " tradeId: " 
             << tradeId << " amount: " << amount << std::endl;
             return "0001";
        }

        std::cout << "模拟微信渠道支付划账成功，uId: " << uId << " tradeId: " 
             << tradeId << " amount: " << amount << std::endl;

        return "0000";
    }
};

// 扩展抽象化角色：支付宝支付
class ZfbPay : public Pay {
public:
    ZfbPay(IPayMode* payMode) : Pay(payMode) { }

    std::string transfer(std::string uId, std::string tradeId, long long amount) {
        std::cout << "模拟支付宝渠道支付划账开始，uId: " << uId << " tradeId: " 
             << tradeId << " amount: " << amount << std::endl;
        bool security = payMode->security(uId);
        if (!security) {
            std::cout << "模拟支付宝渠道支付划账拦截，uId: " << uId << " tradeId: " 
             << tradeId << " amount: " << amount << std::endl;
             return "0001";
        }

        std::cout << "模拟支付宝渠道支付划账成功，uId: " << uId << " tradeId: " 
             << tradeId << " amount: " << amount << std::endl;

        return "0000";
    }
};
#endif // ! BRIDGE_H_