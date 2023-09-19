/*
* Homework #1 -- Problem 2.15
* CS-440
* Austin Pedigo
* Driver for the parallel metrics program
*/

#include <iostream>
#include "MetricFuncts.h"

using namespace std;

int main()
{
	//**variable declaration and initialization**//
	
	int _n = 1, _coreCount = 1, _choice = 1; 
	
	float _serialTime = 0.0, _parallelTime = 0.0,
		_parallelSpeedup = 0.0, _parallelEfficiency = 0.0;
	
	//output to console
	cout << "\nSerial and Parallel Program Metrics Calculator\n\n";
	
	//keeps the user in the app until they chose to leave 
	while(_choice == 1){
		//get core count
		cout << "\nEnter the number of cores you are using: ";
		cin >> _coreCount;

		//get the size of the data set or number of tasks
		cout << "\nEnter the number of tasks or the data set size of the problem: ";
		cin >> _n;

		//compute metrics
		_serialTime = ComputeSerialRunTime(_n);
		_parallelTime = ComputeParalellRunTime(_n, _coreCount);
		_parallelSpeedup = SpeedupParalell(_serialTime, _parallelTime);
		_parallelEfficiency = ParallelEfficiency(_parallelSpeedup, _coreCount);

		//output metrics
		cout << "\n\nSerial Runtime (ms): " << _serialTime << endl;
		cout << "Parallel Runtime (ms): " << _parallelTime << endl;
		cout << "Parallel Speedup: " << _parallelSpeedup << endl;
		cout << "Parallel Efficiency: " << _parallelEfficiency << endl;

		//ask user if they want to continue or exit
		cout << "\nWould you like to enter another program (1 for yes, 2 for no)?\n";
		cin >> _choice;
	}
}