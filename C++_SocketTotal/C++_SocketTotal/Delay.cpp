#pragma once
#include "Common.h"

Delay::Delay()
{
	_timer = new Timer();
	cout << "delay ������" << endl;
}

Delay::~Delay()
{
	delete _timer;
	cout << "delay ���ŵ�" << endl;
}

void Delay::doDelay(double herz)
{
	double currentTime = 0;
	targetTime = calculateTargetTime(herz);
	_timer->setTimer();
	while (currentTime <= targetTime)
	{
		currentTime = _timer->getMicroSecond();
	}
}

double Delay::measureTime(double _time)
{
	measuredTime = _time;
	return measuredTime;
}

double Delay::setTargetTime(double herz)
{
	return targetTime = 1 / herz;
}

double Delay::calculateTargetTime(double herz)
{
	targetTime = setTargetTime(herz);
	if (measuredTime != 0)
	{
		targetTime = (2 * targetTime) - measuredTime;
		if (targetTime < 0)
			targetTime = setTargetTime(herz);
		if (targetTime < setTargetTime(herz) / 2)
			targetTime = setTargetTime(herz) / 2;
	}
	return targetTime - 0.000003;	//�ڿ� ���ڴ� ������, ���� ū ������ ����
}
