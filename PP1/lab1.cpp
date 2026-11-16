#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>
using namespace std;

// Calculates the expression for x. Takes x, returns the value.
double f(double x) {
    return cos(27.0 / 47.0) - 2 * numbers::pi
        + 61 * numbers::e * 7 / ((x + 6) * (x - 10))
        + 15 * sin(x - 12) + 1 / sqrt(x - 9);
}

// Checks that the expression can be calculated for x.
// Takes x, returns true if x is in the domain.
bool isInDomain(double x) {
    return x > 9 && x != 10;
}

int main() {
    cout << "Author: Yaroslav Rasputin ITK-11\n"
        "This program calculates the value of the expression "
        "by given x. Variant 180\n"
        "Enter x (x > 9 and x != 10): ";
    double x{};
    cin >> x;
    if (cin.fail() || (!cin.eof() && !isspace(cin.peek()))) {
        cout << "\nwrong input\n";
        return 0;
    }

    cout << "\n***** do calculations ...";
    const bool defined = isInDomain(x);
    double result{};
    if (defined) {
        result = f(x);
    }
    cout << " done\n";

    cout << fixed << setprecision(5) << "for x = " << x << '\n';
    if (defined) {
        cout << setprecision(9) << "result = " << result << '\n';
    }
    else {
        cout << "result = undefined\n";
    }
    return 0;
}