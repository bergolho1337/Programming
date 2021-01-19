// ---------------------------------------------------------------------------------------------
// Command design pattern:
// 
// ---------------------------------------------------------------------------------------------

#include <iostream>
#include "devices/remote/remote.h"

void simple_remote_test ()
{
	SimpleRemoteControl *remote = new SimpleRemoteControl();
	Light *livingRoomLight = new Light("Living Room");
	Light *kitchenLight = new Light("Kitchen");
	CeilingFan *ceilingFan = new CeilingFan("Living Room");
	GarageDoor *garageDoor = new GarageDoor();
	Stereo *stereo = new Stereo();
	CD *iron_maiden = new CD("Iron Maiden","./src/devices/stereo/cds/iron_maiden.txt");
	CD *metallica = new CD("Metallica","./src/devices/stereo/cds/metallica.txt");

	LightOnCommand *livingRoomLightOn = new LightOnCommand(livingRoomLight);
	LightOffCommand *livingRoomLightOff = new LightOffCommand(livingRoomLight);
	LightOnCommand *kitchenLightOn = new LightOnCommand(kitchenLight);
	LightOffCommand *kitchenLightOff = new LightOffCommand(kitchenLight);

	CeilingFanMediumCommand *ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
	CeilingFanOffCommand *ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

	GarageDoorUpCommand *garageDoorUp = new GarageDoorUpCommand(garageDoor);
	GarageDoorDownCommand *garageDoorDown = new GarageDoorDownCommand(garageDoor);	

	StereoOnWithCDCommand *stereoOnWithCD = new StereoOnWithCDCommand(stereo,iron_maiden);
	StereoOffCommand *stereoOff = new StereoOffCommand(stereo);
	
	remote->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	remote->setCommand(1, kitchenLightOn, kitchenLightOff);
	remote->setCommand(2, ceilingFanMedium, ceilingFanOff);
	remote->setCommand(3, garageDoorUp, garageDoorDown);
	remote->setCommand(4, stereoOnWithCD, stereoOff);

	remote->toString();

	remote->onButtomWasPressed(0);
	remote->offButtomWasPressed(0);
	remote->onButtomWasPressed(1);
	remote->offButtomWasPressed(1);
	remote->onButtomWasPressed(2);
	remote->offButtomWasPressed(2);
	remote->onButtomWasPressed(3);
	remote->offButtomWasPressed(3);
	remote->onButtomWasPressed(4);
	remote->offButtomWasPressed(4);

	stereoOnWithCD->changeCD(metallica);

	remote->onButtomWasPressed(4);
	remote->offButtomWasPressed(4);
}

void remote_with_undo_test ()
{
	RemoteControlWithUndo *remote = new RemoteControlWithUndo();
	Light *livingRoomLight = new Light("Living Room");
	CeilingFan *ceilingFan = new CeilingFan("Living Room");

	LightOnCommand *livingRoomLightOn = new LightOnCommand(livingRoomLight);
	LightOffCommand *livingRoomLightOff = new LightOffCommand(livingRoomLight);
	CeilingFanMediumCommand *ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
	CeilingFanHighCommand *ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
	CeilingFanOffCommand *ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

	remote->setCommand(0, livingRoomLightOn, livingRoomLightOff);
	remote->setCommand(1, ceilingFanMedium, ceilingFanOff);
	remote->setCommand(2, ceilingFanHigh, ceilingFanOff);

	remote->onButtomWasPressed(0);
	remote->offButtomWasPressed(0);

	remote->toString();
	remote->undoBottomWasPressed();

	remote->offButtomWasPressed(0);
	remote->onButtomWasPressed(0);

	remote->toString();
	remote->undoBottomWasPressed();

	printf("\n\n");

	remote->onButtomWasPressed(1);
	remote->offButtomWasPressed(1);
	
	remote->toString();
	remote->undoBottomWasPressed();

	remote->onButtomWasPressed(2);
	remote->toString();
	remote->undoBottomWasPressed();

}

void multiple_commands_test ()
{
	SimpleRemoteControl *remote = new SimpleRemoteControl();

	Light *light = new Light("Living Room");
	Stereo *stereo = new Stereo();
	CD *iron_maiden = new CD("Iron Maiden","./src/devices/stereo/cds/iron_maiden.txt");

	LightOnCommand *lightOn = new LightOnCommand(light);
	StereoOnCommand *stereoOn = new StereoOnCommand(stereo);
	LightOffCommand *lightOff = new LightOffCommand(light);
	StereoOffCommand *stereoOff = new StereoOffCommand(stereo);

	std::vector<Command*> partyOn = { lightOn, stereoOn };
	std::vector<Command*> partyOff = { lightOff, stereoOff };

	MacroCommand *partyOnMacro = new MacroCommand(partyOn);
	MacroCommand *partyOffMacro = new MacroCommand(partyOff);

	remote->setCommand(0, partyOnMacro, partyOffMacro);

	remote->toString();

	printf("------- Pushing Macro On ---------\n");
	remote->onButtomWasPressed(0);
	printf("------- Pushing Macro Off ---------\n");
	remote->offButtomWasPressed(0);
}

int main (int argc, char *argv[])
{
	simple_remote_test();
	//remote_with_undo_test();
	//multiple_commands_test();

	return 0;
}
