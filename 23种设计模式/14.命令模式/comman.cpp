#include "comman.h"
int main()
{
    RemoteControl remoteControl;
    LightOffCommand* pLivingRoomLightOff = new LightOffCommand("Living Room");
    LightOffCommand* pKitchenLightOff = new LightOffCommand("Kitchen");
    LightOnCommand* pLivingRoomLightOn = new LightOnCommand("Living Room");
    LightOnCommand* pKitchenLightOn = new LightOnCommand("Kitchen");
    StereoOnWithCDCommand* pStereoOnWithCD = new StereoOnWithCDCommand("Living Room");
    StereoOffCommand* pStereoOff = new StereoOffCommand("Living Room");

    remoteControl.setCommand(0,pLivingRoomLightOn,pLivingRoomLightOff);
    remoteControl.setCommand(1,pKitchenLightOn,pKitchenLightOff);
    remoteControl.setCommand(2,pStereoOnWithCD,pStereoOff);

    remoteControl.onButtonWasPushed(0);
    remoteControl.offButtonWasPushed(0);
    remoteControl.onButtonWasPushed(1);
    remoteControl.offButtonWasPushed(1);
    remoteControl.onButtonWasPushed(2);
    remoteControl.offButtonWasPushed(2);
return 0;
}