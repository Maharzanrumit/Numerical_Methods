#include <iostream>
#include <iomanip>

using namespace std;

void gaussElimination(double A[10][10], double B[10], int n) {
    // Forward elimination
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = 0; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            B[k] -= factor * B[i];
        }
    }

    // Back-substitution
    double X[10];
    for (int i = n - 1; i >= 0; i--) {
        X[i] = B[i];
        for (int j = i + 1; j < n; j++) {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }

    // Display solution
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << X[i] << endl;
    }
}

int main() {
    int n;
    double A[10][10], B[10];

    cout << "Enter number of equations: ";
    cin >> n;

    cout << "Enter the coefficients of the system (row-wise):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constant terms: ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    gaussElimination(A, B, n);

    return 0;
}

