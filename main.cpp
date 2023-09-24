
#include <iostream>
#include "MyVector.h"
#include <vector>
#include <algorithm>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> vec2;

	Vector<int> vec(10,arr);
	for (auto value : vec)
		std::cout << value << std::endl;
	std::cout<<vec.find(10);
}
