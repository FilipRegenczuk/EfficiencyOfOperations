#pragma once


class Timer
{
public:
	long long int frequency, start, elapsed;
	Timer();
	virtual ~Timer();
	void timerStart();
	void timerStop();
	long long int readQPC();
};