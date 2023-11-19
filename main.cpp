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

const static int N = 1000000;
 static int N_DIV = 100;
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
		for (int j = 0; j < 200; j++)
		{
			//vec.erase(i / 2);
			vec.erase(vec.begin() + i / 2);
			//vec.insert(vec.begin() + i / 2, randAB(0, 1000));


		}
		//vec.push_back(randAB(1, 2));
		auto after = Clock::now();
		using namespace std::chrono;
		duration<double> time_span = duration_cast<duration<double>>(after - before);
		std::cout << i << " " << time_span.count() / 200 << std::endl;

	}
}
int cmp = 0;

bool is_find(int i,int j)
{
	cmp++;
	return i ==j;
}
void testFind()
{
	for (size_t i = N / 10; i <= N; i += N / N_DIV)
	{
		int cmpsum = 0;

		std::vector<int>vec;
		//Vector<int>vec;
		for (int j = 0; j < i; j++)
			vec.push_back(randAB(0, 1000000));
		auto before = Clock::now();

		for (int j = 0; j < 1000; j++)
		{
			int index = randAB(0, i);
			//vec.find(vec[index]);
			std::find(vec.begin(), vec.end(), vec[index]);
		}
	
		auto after = Clock::now();
		using namespace std::chrono;
		duration<double> time_span = duration_cast<duration<double>>(after - before);
		std::cout << i << " " << time_span.count() / 1000 << std::endl;

	}
}
void TestVector(void) {
	int MaxSize = 100000000, Step = MaxSize / 5, Trials = 1000, i = 0, j = 0;
	float t1, t2;
	for (i = Step; i <= MaxSize; i += Step) {
		//std::vector<int> vec;
		Vector<int> vec;
		for (j = 0; j < i; j++)
			vec.push_back(j);
		t1 = GetTickCount();
		for (j = 0; j < Trials; j++)
			vec.erase(i / 2);
			//vec.push_back(j);
			//vec.insert( i / 2, j);
		t2 = GetTickCount();
		std::cout << i << " " << (t2 - t1) / Trials <<std::endl;
	}

}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	Vector<int> test(20,arr); 
	for (int i = 0; i < 3; i++)
	{
		int index = randAB(0, test.Size());
		std::cout << "Delete element: " << test[index / 2] << std::endl;
		test.erase(index / 2);

	}

	for (auto it = test.begin(); it != test.end(); ++it)
		std::cout << *it << std::endl;
	//std::vector<int>vec;
	//for (int i = 0; i < 100; i++)
	//{
	//	vec.push_back(100);
	//	std::cout << "Vec capacity on iteration number :" << i << "   " << vec.capacity() << std::endl;
	//}
	//test.printDebug();
	//testPushBack();
	//testInsert();
	//testErase();
	//testFind();
	//TestVector();
}
