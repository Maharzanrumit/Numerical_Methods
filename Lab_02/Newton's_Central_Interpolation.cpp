#include <iostream>

using namespace std;

void dividedDifference(double x[], double y[], int n) {
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            y[i] = (y[i] - y[i - 1]) / (x[i] - x[i - j]);
        }
    }
}

double newtonInterpolation(double x[], double y[], int n, double value) {
    double result = y[0];
    double term = 1;
    for (int i = 1; i < n; i++) {
        term *= (value - x[i - 1]);
        result += term * y[i];
    }
    return result;
}

int main() {
    double x[] = {1, 2, 3, 4};
    double y[] = {1, 4, 9, 16};
    int n = sizeof(x) / sizeof(x[0]);
    dividedDifference(x, y, n);
    double value = 2.5;
    double approxValue = newtonInterpolation(x, y, n, value);
    cout << "Approximate value at x = " << value << " is " << approxValue << endl;
    return 0;
}

