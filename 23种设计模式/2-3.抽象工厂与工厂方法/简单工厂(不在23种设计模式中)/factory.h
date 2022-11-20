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
    CarFactory()
    {

    }
     BridgeCar *createBridgeCar(string car) 
     {
        if(car=="Honda")
        {
            return new HondaBridgeCar;
        }
        else if(car=="Bmw")
        {
            return new BmwBridgeCar;
        }
        else if(car=="Benz")
        {
            return new BenzBridgeCar;
        }
     }
     ~CarFactory(){};
};

