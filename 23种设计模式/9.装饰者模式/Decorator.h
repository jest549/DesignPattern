#include <iostream>
#include <string>
//抽象组件类-饮料
class Beverage
{
public:
	Beverage() :m_description("Unknown Beverage")
	{
 
	}
	virtual std::string getDescription(){ return m_description; }
	virtual double cost() = 0;//纯虚函数
protected:
	std::string m_description;
};
 
//抽象装饰者类-调料，继承自饮料类
class CondimentDecorator :public Beverage
{
public:
	CondimentDecorator(Beverage* berverge) 
		:m_beverage(berverge)
	{
 
	}
	virtual std::string getDescription() = 0;//定义成纯虚函数，是为了强制子类实例化时必须实现它。
protected:
	Beverage* m_beverage;
};

//三个具体组件
class DarkRoast :public Beverage
{
public:
	DarkRoast()
	{
		m_description = "DarkRoast";
	}
	double cost()
	{
		return 2.99;
	}
};
 
class Espresso :public Beverage
{
public:
	Espresso()
	{
		m_description = "Espresso";
	}
	double cost()
	{
		return 1.99;
	}
};
 
class HouseBlend :public Beverage
{
public:
	HouseBlend()
	{
		m_description = "HouseBlend";
	}
	double cost()
	{
		return 0.89;
	}
};
//两个具体装饰者
class Mocha :public CondimentDecorator
{
public:
	Mocha(Beverage* beverage) :CondimentDecorator(beverage)
	{
	}
 
	std::string getDescription()
	{
		return  m_beverage->getDescription() + " Mocha";
	}
 
	double cost()
	{
		return 0.2 + m_beverage->cost();
	}
};
 
 
class Milk :public CondimentDecorator
{
public:
	Milk(Beverage* beverage) :CondimentDecorator(beverage)
	{
		
	}
 
 
	std::string getDescription()
	{
		return  m_beverage->getDescription() + " Milk";
	}
 
	double cost()
	{
		return 0.5 + m_beverage->cost();
	}
};


