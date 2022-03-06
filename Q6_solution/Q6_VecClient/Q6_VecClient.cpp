#include "../Q6_vecLibrary/ArrVec.h"
#include <iostream>

using namespace VecLibrary;

int main() {
	

	double va[] = { 1, 2, 3, 4, 5 };
	double* a = &va[0];
	Vector v{ 10, a };
	std::cout << v[1] << " " << v[5] << std::endl;
	v.resize(10);
	std::cout << v[1] << " " << v[5] << std::endl;

	return 0;
}
