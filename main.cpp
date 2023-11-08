
#include <iostream>
#include "MyVector.h"
#include <vector>
#include <algorithm>
#include <random>
#include <Windows.h>
int randAB(int min, int max)
{
	return (((rand()) << 15) | rand())
		% (max - min) + min;
}
int main()
{
	int N = 10000000;
	int M = N / 10;
	int step = M;
	int count = 0;
	ULONGLONG time = 0;
	Vector<int> vec;
	int i = 0;
	for (; i < 10; i++)
		vec.push_back(i);
	vec.insert(10,11);
	for (auto it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	//for (int j = 0; j < 10; j++,M+=step) {
	//	std::vector<int> vec;

	//	auto beforeT = GetTickCount64();
	//	for (int i = 0;i<M;i++)
	//		vec.push_back(randAB(1, 2));
	//	auto afterT = GetTickCount64();
	//	std::cout <<M << " " << (afterT - beforeT)/M  << std::endl;
	//}
	
	/*time = 0;
	for (int i = 0; i < 100000; i++)
	{
		auto beforeT = GetTickCount64();
		vec2.push_back(randAB(1, 2));
		auto afterT = GetTickCount64();
		time += afterT - beforeT;
	}
	std::cout << 1000 << " " << time << std::endl;*/

}
