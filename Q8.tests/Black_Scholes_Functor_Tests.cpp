#include <math.h>

#include "pch.h"
#include "../Q8_solution/bisection_method.h"
#include "../Q8_solution/BlackScholesCallFunctor.h"


TEST(TestCaseName, BisectionMethodWorksWithBlackScholesCallFunctor) {
	BlackScholesCallFunctor functor(0.25, 95, 100, 10);
	double epsilon = 0.000000001;
	double actual = bisection_method<BlackScholesCallFunctor>(13.6953, 100, -1, epsilon, functor);
	EXPECT_TRUE((actual <= 50+epsilon) && (actual >= 50-epsilon));
}

