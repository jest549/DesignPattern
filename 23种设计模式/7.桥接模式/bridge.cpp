
#include "bridge.h"
// 客户端使用
int main() {
    std::cout << "--------模拟测试场景：微信支付、人脸方式------------" << std::endl;
    Pay* wxPay = new WxPay(new PayFaceMode());
    wxPay->transfer("weixin_1024343434", "124243434", 243243);

    std::cout << std::endl;

    std::cout << "--------模拟测试场景：支付宝支付、指纹方式----------" << std::endl;
    Pay* zfbPay = new ZfbPay(new PayCypher());
    zfbPay->transfer("zfb_102434d3434", "12483838434", 233343);
}