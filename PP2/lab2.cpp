#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

const double a = -1.0;
const double b = 1.0;

// Computes S(x) = sum of x^(n+2) / (n! * (n + 2)), n = 0, 1, ...
// Uses x_(n+1) = x_n * x * (n + 2) / ((n + 1) * (n + 3)), x_0 = x^2 / 2.
// Returns the first partial sum whose last term is less than eps in modulus.
double s(double x, double eps)
{
    double term = x * x / 2;
    double sum = term;
    int n = 0;
    while (term >= eps || term <= -eps) {
        term *= x * (n + 2) / ((n + 1) * (n + 3));
        sum += term;
        ++n;
    }
    return sum;
}

// Reads a whole line from cin; the line must be exactly one real number
// (surrounding spaces are allowed). The name is used in error messages.
// Throws std::runtime_error if reading fails and
// std::invalid_argument if the line is not a number.
double readDouble(const char* name)
{
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.fail())
        throw std::runtime_error(std::string("cannot read ") + name);
    std::istringstream in(line);
    double value = 0.0;
    if (!(in >> value))
        throw std::invalid_argument(std::string(name) + " is not a number");
    in >> std::ws;
    if (!in.eof())
        throw std::invalid_argument(std::string(name) + " is not a number");
    return value;
}

// Asks for the point x and returns it.
// Throws std::domain_error if x is outside [a; b].
double readPoint()
{
    std::cout << "Enter a real x from [" << a << "; " << b << "]: ";
    double x = readDouble("x");
    if (x < a || x > b)
        throw std::domain_error("x is outside the domain [a; b]");
    return x;
}

// Asks for the accuracy eps and returns it.
// Throws std::domain_error if eps is not positive.
double readEps()
{
    std::cout << "Enter positive eps: ";
    double eps = readDouble("eps");
    if (eps <= 0)
        throw std::domain_error("eps must be positive");
    return eps;
}

int main()
{
    std::cout << "The author of this program is Rasputin Yaroslav, ITK-11.\n";
    std::cout << "This program calculates the value of the series S(x), "
              << "variant 180, x from [" << a << "; " << b << "].\n";
    try {
        const double x = readPoint();
        const double eps = readEps();
        std::cout << "\n***** do calculations ...";
        const double result = s(x, eps);
        std::cout << " done\n";
        std::cout << std::scientific << std::uppercase
                  << "for x = " << std::setprecision(7) << x << '\n'
                  << "for eps = " << std::setprecision(9) << eps << '\n'
                  << std::fixed << std::setprecision(8)
                  << "result = " << result << '\n';
    }
    catch (const std::exception& e) {
        std::cout << "\n***** error\n" << e.what() << '\n';
    }
}
