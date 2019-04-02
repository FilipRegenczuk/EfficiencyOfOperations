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

void Timer::timeStart()
{
	QueryPerformanceFrequency((LARGE_INTEGER *) & frequency);
	start = readQPC();
}

void Timer::timeStop()
{
	elapsed = readQPC() - start;
	std::cout << "Czas [s] = " << fixed << setprecision(3) << (float)elapsed / frequency << std::endl;
	std::cout << "Czas [ms] = " << setprecision(0) << (1000.0 * elapsed) / frequency << std::endl;
	std::cout << "Czas [us] = " << setprecision(3) << (1000000.0 * elapsed) / frequency << std::endl << std::endl;

	fstream plik;
	plik.open("pomiary.txt");
	if (plik.good())
	{
		plik.seekg(0, plik.end);
		plik << (1000000.0 * elapsed) / frequency << endl;
		plik.flush();
		plik.close();
	}
}

long long int Timer::readQPC()
{
	return 0;
}


