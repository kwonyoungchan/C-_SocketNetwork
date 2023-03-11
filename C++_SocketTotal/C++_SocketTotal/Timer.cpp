#include "Common.h"

void Timer::setTimer()
{
	start = system_clock::now();
}

double Timer::getSecond()
{
	duration<double>sec = duration_cast<seconds>(system_clock::now() - start);
	return sec.count();
}

double Timer::getMilliSecond()
{
	duration<double>sec = duration_cast<milliseconds>(system_clock::now() - start);
	return sec.count();
}

double Timer::getMicroSecond()
{
	duration<double>sec = duration_cast<microseconds>(system_clock::now() - start);
	return sec.count();
}
