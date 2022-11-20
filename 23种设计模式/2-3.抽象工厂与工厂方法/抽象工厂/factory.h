#include <iostream>
using namespace std;
//轿车类
class BridgeCar
{
public:
    virtual void createdCar(void) = 0;
    virtual ~BridgeCar(){};
};

//跑车类
class SportCar
{
public:
    virtual void createdCar(void) = 0;
    virtual ~SportCar(){};
};

//SUV车类
class SUVCar
{
public:
    virtual void createdCar(void) = 0;
    virtual ~SUVCar(){};
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
//奔驰跑车
class BenzSportCar : public SportCar
{
public:
    BenzSportCar()
    {
        cout << "BenzSportCar::BenzSportCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "BenzSportCar::createdCar()" << endl;
    }
    ~BenzSportCar()
    {
        cout << "BenzSportCar::~BenzSportCar()" << endl;
    }
};

//宝马跑车
class BmwSportCar : public SportCar
{
public:
    BmwSportCar()
    {
        cout << "BmwSportCar::BmwSportCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "BmwSportCar::createdCar()" << endl;
    }

    ~BmwSportCar()
    {
        cout << "BmwSportCar::~BmwSportCar()" << endl;
    }
};

//本田跑车
class HondaSportCar : public SportCar
{
public:
    HondaSportCar()
    {
        cout << "HondaSportCar::HondaSportCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "HondaSportCar::createdCar()" << endl;
    }
    ~HondaSportCar()
    {
        cout << "HondaSportCar::~HondaSportCar()" << endl;
    }
};

//奔驰SUV车
class BenzSUVCar : public SUVCar
{
public:
    BenzSUVCar()
    {
        cout << "BenzSUVCar::BenzSUVCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "BenzSUVCar::createdCar()" << endl;
    }
    ~BenzSUVCar()
    {
        cout << "BenzSUVCar::~BenzSUVCar()" << endl;
    }
};

//宝马跑车
class BmwSUVCar : public SUVCar
{
public:
    BmwSUVCar()
    {
        cout << "BmwSUVCar::BmwSUVCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "BmwSUVCar::createdCar()" << endl;
    }

    ~BmwSUVCar()
    {
        cout << "BmwSUVCar::~BmwSUVCar()" << endl;
    }
};

//本田跑车
class HondaSUVCar : public SUVCar
{
public:
    HondaSUVCar()
    {
        cout << "HondaSUVCar::HondaSUVCar()" << endl;
    }

    virtual void createdCar(void)
    {
        cout << "HondaSUVCar::createdCar()" << endl;
    }
    ~HondaSUVCar()
    {
        cout << "HondaSUVCar::~HondaSUVCar()" << endl;
    }
};


//车工厂
class CarFactory
{
public:
    virtual BridgeCar *createBridgeCar(void) = 0;
    virtual SportCar *createSportCar(void) = 0;
    virtual SUVCar *createSUVCar(void) = 0;
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

    virtual SportCar *createSportCar(void)
    {
        return (new BenzSportCar());
    }
    virtual SUVCar *createSUVCar(void)
    {
        return (new BenzSUVCar());
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

    virtual SportCar *createSportCar(void)
    {
        return (new BmwSportCar());
    }
    virtual SUVCar *createSUVCar(void)
    {
        return (new BmwSUVCar());
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

    virtual SportCar *createSportCar(void)
    {
        return (new HondaSportCar());
    }
    virtual SUVCar *createSUVCar(void)
    {
        return (new BmwSUVCar());
    }
    ~HondaFactory()
    {
        cout << "HondaFactory::~HondaFactory()" << endl;
    }
};