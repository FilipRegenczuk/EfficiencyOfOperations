#pragma once


class Timer
{
public:
	long long int frequency, start, elapsed;
	Timer();
	virtual ~Timer();
	void timeStart();
	void timeStop();
	long long int readQPC();
};