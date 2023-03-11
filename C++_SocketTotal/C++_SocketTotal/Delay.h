#pragma once
#include "Common.h"

class Delay
{
private:
	Timer* _timer;
	double measuredTime = 0;
	double targetTime = 0;
public :
	Delay();
	~Delay();

	void doDelay(double herz);
	double measureTime(double _time);
	double setTargetTime(double herz);
	double calculateTargetTime(double herz);
};