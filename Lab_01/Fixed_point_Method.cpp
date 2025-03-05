#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float g(float x) {
    return exp(-x);  // Fixed point function x = e^(-x)
}

int main() {
    float xold, x = 0.0, error = 1.0;
    int itr = 0, maxItr = 100;  // Limit iterations to avoid infinite loops

    cout << "Iteration\t x\t\t g(x)\t\t Error\n";
    cout << "| " << ++itr << " |\t\t| " << fixed << setprecision(5) << x << " |\t\t| " << g(x) << " |\t| " << error << " |\n";

    do {
        xold = x;
        x = g(x);
        error = fabs(x - xold);

        cout << "| " << ++itr << " |\t\t| " << fixed << setprecision(5) << x << " |\t\t| " << g(x) << " |\t| " << error << " |\n";

        if (itr >= maxItr) {  // Prevent infinite loop
            cout << "Method did not converge within " << maxItr << " iterations.\n";
            return 1;
        }
    } while (error > 0.0001);  // Stopping criterion: small error threshold

    cout << "\nRoot of the given equation is " << fixed << setprecision(5) << x << endl;
    cout << "Functional value at root (" << x << ") is " << g(x) << endl;
    cout << "Required number of iterations: " << itr << endl;

    return 0;
}

