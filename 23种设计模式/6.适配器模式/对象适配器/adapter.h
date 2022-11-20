#ifndef _ADAPTER_H_
#define _ADAPTER_H_
#include <iostream>
/* Connect Usb port */
class CUsbDisk
{
public:
    virtual ~CUsbDisk() {}

    virtual void ConnectDevice()
    {
        std::cout << "Connect usb port." << std::endl;
    }
};

/* Connect Type-C port */
class CTypeCInterface
{
public:
    virtual ~CTypeCInterface() {}

    void ConnectDevice()
    {
        std::cout << "Connect Type-C port." << std::endl;
    }
};

/* Usb device connect phone */
class CAdapter : public CUsbDisk
{
public:
    CAdapter()
    {
        mpAdaptee = new CTypeCInterface();
    }

    ~CAdapter()
    {
        if (NULL != mpAdaptee) {
            delete mpAdaptee;
        }
    }

    void ConnectDevice()
    {
        if (NULL != mpAdaptee) {
            mpAdaptee->ConnectDevice();
        } else {
            std::cout << "Adapter abnormal. Connect fail!" << std::endl;
        }
    }

private:
    CTypeCInterface *mpAdaptee;
};


#endif