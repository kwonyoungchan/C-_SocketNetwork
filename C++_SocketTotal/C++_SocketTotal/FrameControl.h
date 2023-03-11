#pragma once
#include "Common.h"

class FrameController
{
private:
	Timer timer;
	Delay delay;
	double time = 0;
public:
	FrameController() {};
	~FrameController() {};
	void doControl(double herz)
	{
		timer.setTimer();
		delay.doDelay(herz);
		time = timer.getMicroSecond();
		delay.measureTime(time);
	}

	void printFrequency()
	{
		cout << "ÇöÀç frame rate :\t" << 1 / time << endl;
	}
};