#include "../Q6_vecLibrary/ArrVec.h"
#include <iostream>

using namespace VecLibrary;

int main() {
	//Vector v{ };
	//std::cout << v.nn << std::endl;

	//Vector v{ };
	//std::cout << v.nn << std::endl;
	//std::cout << v.v << std::endl;

	//Vector v{ 10 };

	/*TODO: Can cast int 1 to double 1.0, but cannot cast int 0 to double 0.0. Why?*/
	//Vector v{ 10, 1 };
	//Vector v{ 10, 0 };

	//double va[] = {1, 2, 3, 4, 5};
	//double* a = &va[0];
	//Vector v{ 10, a };
	//v.get();
	//Vector v{ 4, a };
	//v.get();

	//const Vector v{ 10, 1 };
	//Vector v{ 10, 1 };
	//Vector u{ v };
	//u.get();

	//Vector v{ 10, 1 };
	//Vector u{};
	//u = v;
	//u.get();

	//double va[] = {1, 2, 3, 4, 5};
	//double* a = &va[0];
	//Vector v{ 10, a };
	//cout << v[1] << " " << v[5] << endl;

	//double va[] = {1, 2, 3, 4, 5};
	//double* a = &va[0];
	//Vector v{ 10, a };
	//cout << v[1] <<  endl;
	//v[1] = -2;
	//cout << v[1] << " " << v[5] << endl;

	double va[] = { 1, 2, 3, 4, 5 };
	double* a = &va[0];
	Vector v{ 10, a };
	std::cout << v[1] << " " << v[5] << std::endl;
	v.resize(10);
	std::cout << v[1] << " " << v[5] << std::endl;

	//double va[] = { 1, 2, 3, 4, 5 };
	//double* a = &va[0];
	//Vector v{ 10, a };
	//std::cout << v[1] << " " << v[5] << std::endl;
	//v.assign(10, 1.2);
	//std::cout << v[1] << " " << v[5] << std::endl;

	return 0;
}
