#pragma once
#include"Common.h"

class Timer
{
private:
	system_clock::time_point start;
public:
	Timer() { cout << "timer ����" << endl; }
	~Timer(){ cout << "timer �Ҹ�" << endl; }

	void setTimer();
	double getSecond();
	double getMilliSecond();
	double getMicroSecond();
	double getNanoSecond();
};
