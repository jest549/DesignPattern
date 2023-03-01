#include<vector>
#include<iostream>
#include<algorithm>
//观察者接口
class ObserverInterface
{
public:
	virtual void dosomething() = 0;
	virtual ~ObserverInterface() {}
};
//被观察者接口
class SubjectInterface {
public:
	virtual void add(ObserverInterface*) = 0;
	virtual void remove(ObserverInterface*) = 0;
	virtual void notify() = 0;
	virtual ~SubjectInterface() {}
};


class Me :public SubjectInterface
{
public:
	void add(ObserverInterface* obr)override 
	{
		observer.push_back(obr);
	}
	void remove(ObserverInterface* obr)override
	{
		auto pos = std::find(observer.begin(), observer.end(), obr);
		if (pos != observer.end())
		{
			observer.erase(pos);
		}
	}
	void notify()override
	{
		for (const auto& obs : observer)
		{
			obs->dosomething();
		}
	}
private:
	std::vector<ObserverInterface*>observer;
};

class Wife :public ObserverInterface {
public:
	void dosomething() override {
		std::cout << "妻子收到通知，开始做饭！" << std::endl;
	}
};

class Daughter :public  ObserverInterface {
public:
	void dosomething() override {
		std::cout << "女儿收到通知，去开门！" << std::endl;
	}
};

