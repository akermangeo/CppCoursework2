#include "ArrVec.h"
#include <iostream>

using namespace std;

namespace VecLibrary {

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
		delete v;
		v = new double[nn];
		for (int i = 0; i < nn; i++) {
			v[i] = rhs.v[i];
		}

		return *this;
	};


	void Vector::resize(int newn) {
		nn = newn;
		delete v;
		v = new double[nn];
		for (int i = 0; i < nn; i++) {
			v[i] = 0.0;
		}
	};

	void Vector::assign(int newn, double a) {
		nn = newn;
		delete v;
		v = new double[nn];
		for (int i = 0; i < nn; i++) {
			v[i] = a;
		}
	};
}

