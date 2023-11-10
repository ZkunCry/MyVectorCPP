#include "WriteEx.h"
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
const static int N_DIV = 100;
const static int K = N / 100;


int randAB(int min, int max)
{
	return (((rand()) << 15) | rand())
		% (max - min) + min;
}

void testPushBack() {
	std::string title = "Vector;";
	/*int arr[6] = { 1,2,3,4,5,6 };
	Vector<int>  vec(6,arr);
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << std::endl;
	}*/
	std::vector<std::string> columns;

	for (size_t i = N / 10; i <= N; i += N / N_DIV)
	{
		Vector<int>vec;
		//Vector<int> vec;
		auto before = Clock::now();
		for (int j = 0; j < i; j++)
			//vec.push_back(randAB(1, 2));
			vec.insert(randAB(0, 1000), vec.Size() );
			//vec.insert(randAB(0, 1000),randAB(0,vec.Size()+1));
		auto after = Clock::now();
		using namespace std::chrono;
		duration<double> time_span = duration_cast<duration<double>>(after - before);
		std::cout << i << " " << time_span.count()/ N << std::endl;
		//std::string result = std::to_string(i) + ";" + std::to_string(time_span.count() / 100);
		/*result.replace(result.find('.'), 1, ",");
		columns.push_back(result);*/

	}
	//writeInExcel(title, columns);
}
int main()
{
	Vector<int> test; 
	//test.printDebug();
	testPushBack();
}
