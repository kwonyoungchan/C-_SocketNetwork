#pragma once
#include"Common.h"

class Timer
{
private:
	system_clock::time_point start;
public:
	Timer() { cout << "timer »ý¼º" << endl; }
	~Timer(){ cout << "timer ¼Ò¸ê" << endl; }

	void setTimer();
	double getSecond();
	double getMilliSecond();
	double getMicroSecond();
	double getNanoSecond();
};
