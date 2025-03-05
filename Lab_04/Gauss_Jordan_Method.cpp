#include <iostream>
#include <iomanip>
using namespace std;

void gaussJordan(float a[][10], int n) {
    for (int i = 0; i < n; i++) {
        float pivot = a[i][i];

        for (int j = 0; j <= n; j++) 
            a[i][j] /= pivot;  

        for (int k = 0; k < n; k++) {
            if (k != i) {
                float factor = a[k][i];
                for (int j = 0; j <= n; j++)
                    a[k][j] -= factor * a[i][j];
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;
    float a[10][10];

    cout << "Enter augmented matrix (coefficients and constants):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];

    gaussJordan(a, n);

    cout << "Solution: ";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << fixed << setprecision(3) << a[i][n] << " ";

    return 0;
}

