//Write a program to evaluate integration of a function using Romberg integration formula.
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return exp(-x);
}

double rombergIntegration(double a, double b, int n) {
    double R[n][n], h = b - a;

    R[0][0] = (h / 2) * (f(a) + f(b));

    for (int i = 1; i < n; i++) {
        h /= 2.0;
        double sum = 0.0;

        for (int k = 1; k <= (1 << (i - 1)); k++) {
            sum += f(a + k * h * 2 - h);
        }

        R[i][0] = 0.5 * R[i - 1][0] + h * sum;

        for (int j = 1; j <= i; j++) {
            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }
    }

    return R[n - 1][n - 1];
}

int main() {
    double lower, upper;
    int n;

    cout << "Enter lower limit: ";
    cin >> lower;
    cout << "Enter upper limit: ";
    cin >> upper;
    cout << "Enter number of iterations: ";
    cin >> n;

    double result = rombergIntegration(lower, upper, n);

    cout << fixed << setprecision(6);
    cout << "The integration result is: " << result << endl;

    return 0;
}

