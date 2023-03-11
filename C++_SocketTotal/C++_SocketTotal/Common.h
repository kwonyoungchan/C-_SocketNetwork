#include <iostream>	
#include <string>
#include <chrono>
#include <thread>
#include <WinSock2.h>
#pragma comment (lib,"ws2_32")

#include "FrameControl.h"
#include "Delay.h"
#include "Timer.h"
#include "Socket.h"

using namespace std;
using namespace chrono;
using std::thread;