#include "arr_vector.h"
#include <iostream>

using namespace std;

/* Should I use nullptr? */
Vector::Vector() : nn{ 0 }, v{ nullptr } {};

Vector::Vector(int n, double a) : nn{ n }, v{ new double[nn] } {
	for (int i = 0; i < nn; i++) {
		v[i] = a;
	}
};

Vector::Vector(int n, const double* a) : nn{ n }, v{ new double[nn] } {
	/*Cannot copy a constant pointer by = */
	for (int i = 0; i < nn; i++) {
		v[i] = a[i];  // But one can copy constant double
	}
};

Vector::Vector(const Vector& rhs) : nn{ rhs.nn }, v{ new double[nn] } {
	/*Copy the array to the Vector in case rhs->v changed*/
	for (int i = 0; i < nn; i++) {
		v[i] = rhs.v[i];
	}
};

Vector& Vector::operator=(const Vector& rhs) {
	//nn{ rhs.nn }; /*Why I cannot use {}?*/
	nn = rhs.nn;
	v = new double[nn];
	for (int i = 0; i < nn; i++) {
		v[i] = rhs.v[i];
	}

	return *this;
};

inline double& Vector::operator[](const int i) {
	return v[i];
};

//inline const double& Vector::operator[](const int i) const {
//	//double temp = v[i];
//	return v[i];
//};

//inline const double& Vector::operator[](const int i) const {
//	return *this->v;
//};

inline int Vector::size() const {
	int n = nn;
	return n;
};

void Vector::resize(int newn) {
	Vector new_v = Vector(newn);
	nn = new_v.nn;
	v = new_v.v;
};

void Vector::assign(int newn, double a) {
	Vector new_v = Vector(newn, a);
	nn = new_v.nn;
	v = new_v.v;
};

int main() {
	//Vector v{ };
	//cout << v.nn << endl;
	
	//Vector v{ };
	//cout << v.nn << endl;
	//cout << v.v << endl;

	//Vector v{ 10 };
	//v.get();

	//Vector v{ 10, 1 };
	//v.get();

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

	//double va[] = { 1, 2, 3, 4, 5 };
	//double* a = &va[0];
	//Vector v{ 10, a };
	//cout << v[1] << " " << v[5] << endl;
	//v.resize(10);
	//cout << v[1] << " " << v[5] << endl;

	double va[] = { 1, 2, 3, 4, 5 };
	double* a = &va[0];
	Vector v{ 10, a };
	cout << v[1] << " " << v[5] << endl;
	v.assign(10, 1.2);
	cout << v[1] << " " << v[5] << endl;

	return 0;
}