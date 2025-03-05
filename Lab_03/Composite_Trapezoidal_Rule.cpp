//Write a program to calculate integration using composite Trapezoidal rule. 
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fun(double x) {
    return exp(-x);
}

double trapezoidalRule(double lwr, double upr, int n) {
    double h = (upr - lwr) / n;
    double sum = fun(lwr) + fun(upr);

    for (int i = 1; i < n; i++) {
        double x = lwr + i * h;
        sum += 2 * fun(x);
    }

    return (h / 2) * sum;
}

int main() {
    double lwr, upr;
    int n;

    cout << "Enter the lower limit, upper limit, and number of subintervals: ";
    cin >> lwr >> upr >> n;

    double I = trapezoidalRule(lwr, upr, n);

    cout << fixed << setprecision(6);
    cout << "The integration of f(x) = exp(-x) is " << I << endl;

    return 0;
}

