#include <iostream>
using namespace std;

void gaussSeidel(int n, float A[10][10], float B[10], int iterations) {
    float X[10] = {0};  

    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < n; i++) {
            float sum = 0;
            for (int j = 0; j < n; j++) {
                if (j != i)
                    sum += A[i][j] * X[j];  
            }
            X[i] = (B[i] - sum) / A[i][i];  
        }
    }

    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << X[i] << "\n";
}

int main() {
    int n, iterations;
    cout << "Enter number of equations: ";
    cin >> n;

    float A[10][10], B[10];
    cout << "Enter coefficient matrix A (row-wise):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter constant matrix B:\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    cout << "Enter number of iterations: ";
    cin >> iterations;

    gaussSeidel(n, A, B, iterations);

    return 0;
}

