#include <iostream>
#include <cmath>

// Function to return the value of d_1 or d_2
// Parameters:
// (int) i = select whether to return d_1 or d_2.
// (double) S = Price of underlying
// (double) K = Strike
// (double) t = Expiry (in years)
// (double) r = Risk-free rate in percentage per annum 
// (double) sigma = volatility of underlying asset in percentage per annum

double d_i(const int& i, const double& S, const double& K, const double& t, const double& r, const double& sigma) 
{
    double d_1 = (log(S / K) + ((r / 100) + sigma * sigma / (2 * 100 * 100)) * t) / (sqrt(t) * (sigma / 100));
    if (i == 1)
        return d_1;
    else
        return d_1 - (sqrt(t) * (sigma/100));
}

// Standard Gaussian CDF using the error function.
// Parameters:
// (double) x = value at wich to evaluate cdf

double std_gaussian_cdf(const double& x)
{
    return 0.5 * erfc(-x * sqrt(0.5));
}

// Computes Black-Scholes Call Price of an asset paying no dividends.
// Parameters:
// (double) S = Price of underlying
// (double) K = Strike
// (double) t = Expiry (in years)
// (double) r = Risk-free rate in percentage per annum
// (double) sigma = volatility of underlying asset in percentage per annum

double call_price(const double& S, const double& K, const double& t, const double& r, const double& sigma)
{
    return S * std_gaussian_cdf(d_i(1, S, K, t, r, sigma)) - K * exp(-(r / 100) * t) * std_gaussian_cdf(d_i(2, S, K, t, r, sigma));
}

int main()
{
    using namespace std;
    /*
    cout << "Input European Call Expiry in years: ";
    double t = 0;
    cin >> t;
    cout << "Input Call Strike: ";
    double K = 0;
    cin >> K;
    cout << "Input Price of Underlying: ";
    double S = 0;
    cin >> S;
    cout << "Input Volatility of Underlying in percentage per annum: ";
    double sigma = 0;
    cin >> sigma;
    cout << "Input Risk-Free Rate in percentage per annum: ";
    double r = 0;
    cin >> r; */

    double t = 0.25;
    double K = 95;
    double S = 100;
    double sigma = 50;
    double r = 10;

    double call = call_price(S, K, t, r, sigma);

    cout << "Call Price: " << call << " USD";

    return 0;
}