
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
	int count = 0;
	ULONGLONG time = 0;
	Vector<int>vec3;
	vec3.push_back(1);
	vec3.push_back(2);
	Vector<int> vec(vec3);

	std::vector<int> vec2;
	
	for (int i = 0; i < 1000000; i++)
	{
		auto beforeT= GetTickCount64();
		vec.push_back(randAB(1, 2));
		auto afterT= GetTickCount64();
		time += afterT - beforeT;
		//std::cout << vec.Size()<<std::endl;
	}
	std::cout << 1000 << " " << time  << std::endl;
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
