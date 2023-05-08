
#include <iostream>
#include "MyVector.h"

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	Vector<int> vec(10,arr);
	vec.push_back(999);
	vec.push_back(9991);
}
