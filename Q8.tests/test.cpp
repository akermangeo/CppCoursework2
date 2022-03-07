#include <math.h>

#include "pch.h"
#include "../Q8_solution/bisection_method.h"

class IdentityFunctor {
public:

	double operator()(double sigma)const
	{
		return sigma;
	}
};

class CubeFunctor {
public:

	double operator()(double sigma)const
	{
		return sigma*sigma*sigma;
	}
};

TEST(TestCaseName, Identity) {
	IdentityFunctor functor;
	double epsilon = 0.000000001;
	double actual = bisection_method<IdentityFunctor>(0., 1., -0.12321321321, epsilon, functor);
	EXPECT_TRUE((actual <= epsilon) && (actual >= -epsilon));
}

TEST(TestCaseName, Cube) {
	CubeFunctor functor;
	double epsilon = 0.000000001;
	double actual = pow(bisection_method<CubeFunctor>(0., 1., -0.12321321321, epsilon, functor),3);
	EXPECT_TRUE((actual <= epsilon) && (actual >= -epsilon));
}