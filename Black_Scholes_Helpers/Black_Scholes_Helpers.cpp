#include <cmath>

#include "Black_Scholes_Helpers.h"

double d_i(const Constant_Type& constant_to_produce, const double& S, const double& K, const double& t, const double& r, const double& sigma)
{
    double d_1 = (log(S / K) + ((r / 100) + sigma * sigma / (2 * 100 * 100)) * t) / (sqrt(t) * (sigma / 100));
    if (constant_to_produce == Constant_Type::d1)
        return d_1;
    else
        return d_1 - (sqrt(t) * (sigma / 100));
}

double std_gaussian_cdf(const double& x)
{
    return 0.5 * erfc(-x * sqrt(0.5));
}

double call_price(const double& S, const double& K, const double& t, const double& r, const double& sigma)
{
    return S * std_gaussian_cdf(d_i(Constant_Type::d1, S, K, t, r, sigma)) - K * exp(-(r / 100) * t) * std_gaussian_cdf(d_i(Constant_Type::d2, S, K, t, r, sigma));
}
