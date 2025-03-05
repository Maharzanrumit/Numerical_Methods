#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float fun(float x) {
    return exp(-x);
}

int main() {
    int n;
    float I = 0.0, h, lwr, upr, sum_odd = 0.0, sum_even = 0.0;

    cout << "Enter the lower limit, upper limit, and number of subintervals (even only): ";
    cin >> lwr >> upr >> n;

    if (n % 2 != 0) {
        cout << "Error: Number of subintervals must be even!" << endl;
        return 1;
    }

    h = (upr - lwr) / n;

    for (int i = 1; i < n; i += 2) {
        sum_odd += fun(lwr + i * h);
    }

    for (int i = 2; i < n; i += 2) {
        sum_even += fun(lwr + i * h);
    }

    I = (h / 3.0) * (fun(lwr) + 4.0 * sum_odd + 2.0 * sum_even + fun(upr));

    cout << fixed << setprecision(6);
    cout << "The integration of f(x) = exp(-x) is: " << I << endl;

    return 0;
}

