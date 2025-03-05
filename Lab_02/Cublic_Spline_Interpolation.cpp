#include <iostream>
#include <cmath>  // For mathematical functions

using namespace std;

void cubicSplineInterpolation(int arrx[], int arry[], int n, int x) {
    // Arrays for storing the coefficients and intermediate values
    double h[n-1], alpha[n-1], l[n], mu[n-1], z[n], a[n], b[n-1], c[n], d[n-1];

    // Initialize the boundary conditions
    l[0] = 1.0;
    z[0] = 0.0;
    c[0] = 0.0;

    // Step 1: Calculate the h, alpha, l, mu, and z arrays
    for (int i = 0; i < n-1; i++) {
        h[i] = arrx[i+1] - arrx[i];
        if (i != 0) {
            alpha[i] = (3.0 / h[i]) * (arry[i+1] - arry[i]) - (3.0 / h[i-1]) * (arry[i] - arry[i-1]);
        }
    }

    // Step 2: Solve for c using the tridiagonal matrix algorithm
    for (int i = 1; i < n-1; i++) {
        l[i] = 2.0 * (arrx[i+1] - arrx[i-1]) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
    }

    l[n-1] = 1.0;
    z[n-1] = 0.0;
    c[n-1] = 0.0;

    // Step 3: Calculate b and d coefficients
    for (int j = n-2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j+1];
        b[j] = (arry[j+1] - arry[j]) / h[j] - h[j] * (c[j+1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j+1] - c[j]) / (3.0 * h[j]);
    }

    // Step 4: Find the appropriate interval for the given x
    int i = 0;
    while (x > arrx[i+1] && i < n-1) {
        i++;
    }

    // Calculate the interpolated value at x
    double dx = x - arrx[i];
    double result = arry[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;

    // Output the result
    cout << "The interpolated value at x = " << x << " is: " << result << endl;
}

int main() {
    int n, x;

    // Input the number of data points
    cout << "Enter the number of data points (n): ";
    cin >> n;

    // Arrays for x and y values
    int arrx[n], arry[n];

    // Input the x and y values for the data points
    for (int i = 0; i < n; ++i) {
        cout << "Enter x[" << i << "]: ";
        cin >> arrx[i];
        cout << "Enter y[" << i << "]: ";
        cin >> arry[i];
    }

    // Input the x value where we want to interpolate
    cout << "Enter the value of x for interpolation: ";
    cin >> x;

    // Perform cubic spline interpolation
    cubicSplineInterpolation(arrx, arry, n, x);

    return 0;
}

