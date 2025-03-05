#include <iostream>
#include <cmath>
#include <sstream>  // For stringstream
using namespace std;

// Function to evaluate polynomial using Horner's method
double hornerMethod(int coeff[], int degree, double x) {
    double result = coeff[0];  // Start with the highest degree coefficient
    for (int i = 1; i <= degree; ++i) {
        result = result * x + coeff[i];  // Horner's method step
    }
    return result;
}

// Synthetic Division (Horner's method)
void syntheticDivision(int coeff[], int& degree, double root) {
    double temp = coeff[0];
    
    // Perform synthetic division using Horner's method
    for (int i = 1; i <= degree; ++i) {
        coeff[i] += root * coeff[i - 1];
    }
    
    // Decrease degree and handle the reduced polynomial
    degree--;
}

// Function to convert an integer to a string (using ostringstream)
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Function to find all roots of the polynomial
void findRoots(int coeff[], int& degree) {
    int foundRoots = 0;
    // Trial for integer roots within range [-10, 10]
    for (int i = -10; i <= 10; ++i) {
        // Evaluate polynomial at i using Horner's method
        if (fabs(hornerMethod(coeff, degree, i)) < 1e-6) {  // If the result is close to 0, it's a root
            cout << "Found root: " << i << endl;
            foundRoots++;
            
            // Perform synthetic division on the polynomial using this root
            syntheticDivision(coeff, degree, i);
            
            i--;  // Recheck the same value in case it is a repeated root
        }
    }
    
    if (foundRoots == 0) {
        cout << "No integer roots found in the range [-10, 10]." << endl;
    }
    
    // Output the remaining polynomial
    cout << "Remaining polynomial after finding roots: ";
    for (int i = 0; i <= degree; ++i) {
        cout << coeff[i] << (i < degree ? "x^" + intToString(degree - i) + " + " : "");
    }
    cout << endl;
}

int main() {
    int degree;

    // Input the degree of the polynomial
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    int coeff[degree + 1];

    // Input the coefficients from highest degree to constant term
    for (int i = degree; i >= 0; --i) {
        cout << "Enter the coefficient of x^" << i << ": ";
        cin >> coeff[degree - i];  // Store coefficients in reverse order
    }

    // Find all the roots of the polynomial
    findRoots(coeff, degree);

    return 0;
}

