/*
* Homework #1 -- Problem 2.15
* CS-440
* Austin Pedigo
* Functions for the parallel metrics program
*/

#include <math.h>

#pragma once

float ComputeSerialRunTime(int _n)
{
	//compute the serial run time for the program using one core

	float _serialRuntime = 0.0;

	_serialRuntime = _n * _n;

	return _serialRuntime;
}

float ComputeParalellRunTime(int _n, int _coreCount)
{
	//compute the parallel runtime for the program using multiple cores
	float _parallelSerialRuntime = 0.0;

	_parallelSerialRuntime = (_n * _n) / _coreCount;
	_parallelSerialRuntime += log2f(_coreCount);

	return _parallelSerialRuntime;
}

float SpeedupParalell(float _serialRunTime, float _parallelRunTime)
{
	//compute the speedup for the parallel program versus the serial program
	float _parallelSpeedUp = 0.0;

	_parallelSpeedUp = _serialRunTime / _parallelRunTime;

	return _parallelSpeedUp;
}

float ParallelEfficiency(float _speedUp, int _coreCount)
{
	//compute the parallel program's efficiency
	float _parallelEffiency = 0.0;

	_parallelEffiency = _speedUp / _coreCount;

	return _parallelEffiency; 
}
