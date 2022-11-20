#ifndef _ADAPTER_H_
#define _ADAPTER_H_


#include <iostream>

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

/* Not only connect Usb port, but also connect Type-C port */
class CAdapter : public CUsbDisk, public CTypeCInterface
{
public:
    void ConnectDevice()
    {
        CTypeCInterface::ConnectDevice();
    }
};

#endif // !_ADAPTER_H_