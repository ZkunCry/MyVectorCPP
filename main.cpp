#include <iostream>
#include "MyVector.h"
#include <vector>
#include <algorithm>
#include <random>
#include <Windows.h>
#include <ctime>
#include <chrono>
#include <ratio>
#include <math.h>
typedef std::chrono::high_resolution_clock Clock;

const static int N = 2000000;
const static int N_DIV = 100;
const static int K = N / 100;


int randAB(int min, int max)
{
	return (((rand()) << 15) | rand())
		% (max - min) + min;
}

void testPushBack() {
	std::string title = "Vector;";
	std::vector<std::string> columns;

	for (size_t i = N / 10; i <= N; i += N / N_DIV)
	{
		std::vector<int>vec;
		auto before = Clock::now();
		for (int j = 0; j < 100; j++)
			vec.push_back(randAB(1, 2));
		auto after = Clock::now();
		using namespace std::chrono;
		duration<double> time_span = duration_cast<duration<double>>(after - before);
		std::cout << i << " " << time_span.count()/ 100 << std::endl;

	}

}
void testInsert()
{
	for (size_t i = N / 10; i <= N; i += N / N_DIV)
	{
		std::vector<int>vec;
		//Vector<int>vec;
		for (int j = 0; j < i; j++)
			vec.push_back(randAB(0, 1000));
		auto before = Clock::now();
		for (int j = 0; j < 100; j++)
		{
			vec.insert(vec.begin() + i / 2, randAB(0, 1000));
			//vec.insert(randAB(0, 1000), i/2);
				//vec.insert(vec.begin()+ (vec.size()/2), randAB(0, 1000));

		}
		//vec.push_back(randAB(1, 2));
		auto after = Clock::now();
		using namespace std::chrono;
		duration<double> time_span = duration_cast<duration<double>>(after - before);
		std::cout << i << " " << time_span.count() / 100 << std::endl;

	}
}
void testErase()
{
	for (size_t i = N / 10; i <= N; i += N / N_DIV)
	{
		std::vector<int>vec;
		//Vector<int>vec;
		for (int j = 0; j < i; j++)
			vec.push_back(randAB(0, 1000));
		auto before = Clock::now();
		for (int j = 0; j < 100; j++)
		{
			//vec.erase(i / 2);
			vec.erase(vec.begin());
			//vec.insert(vec.begin() + i / 2, randAB(0, 1000));
			//vec.insert(randAB(0, 1000), i/2);
				//vec.insert(vec.begin()+ (vec.size()/2), randAB(0, 1000));

		}
		//vec.push_back(randAB(1, 2));
		auto after = Clock::now();
		using namespace std::chrono;
		duration<double> time_span = duration_cast<duration<double>>(after - before);
		std::cout << i << " " << time_span.count() / 100 << std::endl;

	}
}
int main()
{
	//Vector<int> test; 
	//std::vector<int>vec;
	//for (int i = 0; i < 100; i++)
	//{
	//	vec.push_back(100);
	//	std::cout << "Vec capacity on iteration number :" << i << "   " << vec.capacity() << std::endl;
	//}
	//test.printDebug();
	//testPushBack();
	//testInsert();
	testErase();
}
