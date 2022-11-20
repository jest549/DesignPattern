/* Connect Usb port */
#include "adapter.h"

int main(int argc, char *argv[])
{
    CUsbDisk *theDisk = new CAdapter();

    theDisk->ConnectDevice();

    delete theDisk;
    return 0;
}