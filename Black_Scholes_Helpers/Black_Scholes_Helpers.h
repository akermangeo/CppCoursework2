/// <summary>
/// Specifies which constant we are referring to in the B-S call price forlmula.
/// </summary>
enum class Constant_Type { d1, d2 };

// Function to return the value of d_1 or d_2
// Parameters:
// (int) i = select whether to return d_1 or d_2.
// (double) S = Price of underlying
// (double) K = Strike
// (double) t = Expiry (in years)
// (double) r = Risk-free rate in percentage per annum 
// (double) sigma = volatility of underlying asset in percentage per annum
double d_i(const Constant_Type& constant_to_produce, const double& S,
    const double& K, const double& t, const double& r, const double& sigma);

// Standard Gaussian CDF using the error function.
// Parameters:
// (double) x = value at wich to evaluate cdf
double std_gaussian_cdf(const double& x);

// Computes Black-Scholes Call Price of an asset paying no dividends.
// Parameters:
// (double) S = Price of underlying
// (double) K = Strike
// (double) t = Expiry (in years)
// (double) r = Risk-free rate in percentage per annum
// (double) sigma = volatility of underlying asset in percentage per annum
double call_price(const double& S, const double& K, const double& t, const double& r, const double& sigma);
