/* Klasa Timer mierzy czas wykonujacych sie procesow */

#include "Timer.h"
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>



Timer::Timer()
{
}

Timer::~Timer()
{
}

void Timer::timerStart()
{
	QueryPerformanceFrequency((LARGE_INTEGER *) & frequency);
	start = readQPC();
}

void Timer::timerStop()
{
	elapsed = readQPC() - start;
	std::cout << "Czas [s] = " << std::fixed << std::setprecision(3) << (float)elapsed / frequency << std::endl;
	std::cout << "Czas [ms] = " << std::setprecision(0) << (1000.0 * elapsed) / frequency << std::endl;
	std::cout << "Czas [us] = " << std::setprecision(3) << (1000000.0 * elapsed) / frequency << std::endl << std::endl;

	std::fstream file;
	file.open("pomiary.txt");
	if (file.good())
	{
		file.seekg(0, file.end);
		file << (1000000.0 * elapsed) / frequency << std::endl;
		file.flush();
		file.close();
	}
}

long long int Timer::readQPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}


