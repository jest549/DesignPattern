#include <iostream>
using namespace std;
//轿车类
class BridgeCar
{
public:
    virtual void createdCar(void) = 0;
    virtual ~BridgeCar(){};
};

//奔驰轿车
class BenzBridgeCar : public BridgeCar
{
public:
    BenzBridgeCar()
    {
        cout << "BenzBridgeCar::BenzBridgeCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "BenzBridgeCar::createdCar()" << endl;
    }
    ~BenzBridgeCar()
    {
        cout << "BenzBridgeCar::~BenzBridgeCar()" << endl;
    }
};

//宝马轿车
class BmwBridgeCar : public BridgeCar
{
public:
    BmwBridgeCar()
    {
        cout << "BmwBridgeCar::BmwBridgeCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "BmwBridgeCar::createdCar()" << endl;
    }

    ~BmwBridgeCar()
    {
        cout << "BmwBridgeCar::~BmwBridgeCar()" << endl;
    }
};

//本田轿车
class HondaBridgeCar : public BridgeCar
{
public:
    HondaBridgeCar()
    {
        cout << "HondaBridgeCar::HondaBridgeCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "HondaBridgeCar::createdCar()" << endl;
    }
    ~HondaBridgeCar()
    {
        cout << "HondaBridgeCar::~HondaBridgeCar()" << endl;
    }
};



//车工厂
class CarFactory
{
public:
    virtual BridgeCar *createBridgeCar(void) = 0;
    virtual ~CarFactory(){};
};

//奔驰车工厂
class BenzFactory : public CarFactory
{
public:
    BenzFactory(){}

    virtual BridgeCar *createBridgeCar(void)
    {
        return (new BenzBridgeCar());
    }

    ~BenzFactory()
    {
        cout << "BenzFactory::~BenzFactory()" << endl;
    }
};

//宝马车工厂
class BmwFactory : public CarFactory
{
public:
    BmwFactory() {}

    virtual BridgeCar *createBridgeCar(void)
    {
        return (new BmwBridgeCar());
    }


    ~BmwFactory()
    {
        cout << "BmwFactory::~BmwFactory()" << endl;
    }
};
//本田车工厂
class HondaFactory : public CarFactory
{
public:
    HondaFactory() {}

    virtual BridgeCar *createBridgeCar(void)
    {
        return (new HondaBridgeCar());
    }

    ~HondaFactory()
    {
        cout << "HondaFactory::~HondaFactory()" << endl;
    }
};