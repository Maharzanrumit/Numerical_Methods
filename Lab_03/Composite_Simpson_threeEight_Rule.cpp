#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float fun(float x) {
    return exp(-x);
}

int main() {
    int n;
    float I = 0.0, h, lwr, upr, sum_multiples_of_3 = 0.0, sum_non_multiples_of_3 = 0.0;

    cout << "Enter the lower limit, upper limit, and number of subintervals (multiple of 3 only): ";
    cin >> lwr >> upr >> n;

    if (n % 3 != 0) {
        cout << "Error: Number of subintervals must be a multiple of 3!" << endl;
        return 1;
    }

    h = (upr - lwr) / n;

    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum_multiples_of_3 += fun(lwr + i * h); 
        } else {
            sum_non_multiples_of_3 += fun(lwr + i * h); 
        }
    }
    I = (3 * h / 8.0) * (fun(lwr) + 3.0 * sum_non_multiples_of_3 + 2.0 * sum_multiples_of_3 + fun(upr));

    cout << fixed << setprecision(6);
    cout << "The integration of f(x) = exp(-x) is: " << I << endl;

    return 0;
}

