#include <iostream>
#include <cmath>
using namespace std;

void powerMethod(float A[10][10], float X[10], int n) {
    float newX[10], lambda_old = 1, lambda_new = 0;
    
    while (true) {
        // Step 1: Multiply A * X
        for (int i = 0; i < n; i++) {
            newX[i] = 0;
            for (int j = 0; j < n; j++) {
                newX[i] += A[i][j] * X[j];
            }
        }

        // Step 2: Find the largest value (approximate eigenvalue)
        lambda_new = newX[0];
        for (int i = 1; i < n; i++) {
            if (fabs(newX[i]) > fabs(lambda_new))
                lambda_new = newX[i];
        }

        // Step 3: Normalize the new X
        for (int i = 0; i < n; i++)
            X[i] = newX[i] / lambda_new;

        // Step 4: Check if the eigenvalue change is less than 5%
        if (fabs(lambda_new - lambda_old) / fabs(lambda_old) < 0.05)
            break;

        lambda_old = lambda_new; // Update old eigenvalue
    }

    // Print Results
    cout << "Dominant Eigenvalue: " << lambda_new << endl;
    cout << "Eigenvector: ";
    for (int i = 0; i < n; i++)
        cout << X[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    float A[10][10], X[10];

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter initial guess vector X:\n";
    for (int i = 0; i < n; i++)
        cin >> X[i];

    powerMethod(A, X, n);

    return 0;
}

