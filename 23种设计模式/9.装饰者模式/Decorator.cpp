#include "Decorator.h"
//测试代码
int main()
{
	//不加调料的Espresso
	Beverage* beverage = new Espresso();
	std::cout << beverage->getDescription() << " ￥" << beverage->cost() << std::endl;
 
	//加双倍摩卡和奶泡的DarkRoast
	Beverage* beverage2 = new DarkRoast();
	beverage2 = new Mocha(beverage2);
	beverage2 = new Mocha(beverage2);
	beverage2 = new Milk(beverage2);
	std::cout << beverage2->getDescription() << " ￥" << beverage2->cost() << std::endl;
 
	//加双倍奶泡的和一份摩卡的HouseBlend
	Beverage* beverage3 = new HouseBlend();
	beverage3 = new Mocha(beverage3);
	beverage3 = new Milk(beverage3);
	beverage3 = new Milk(beverage3);
	std::cout << beverage3->getDescription() << " ￥" << beverage3->cost() << std::endl;
	delete beverage;
	delete beverage2;
	delete beverage3;
}