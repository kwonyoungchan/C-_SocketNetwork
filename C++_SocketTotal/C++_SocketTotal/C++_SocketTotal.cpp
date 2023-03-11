#include "Common.h"

int main()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = 0;
	cursorCoord.Y = 0;
	FrameController frameController;
	UDP myUDP;
	myUDP.setSockAddrforClient((char*)"192.168.1.227",7777);
	//myUDP.binding();
	while (1)
	{
		char buffer[] = "hello world!";
		myUDP.sendPacket(buffer);
		myUDP.showPacketData(buffer);
		frameController.doControl(60);
		frameController.printFrequency();
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorCoord);
	}


}