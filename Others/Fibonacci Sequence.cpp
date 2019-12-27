#include <iostream>

using namespace std;

int modulo = 1000000000 + 7;

// Multiply matrices and store final value in the first matrix
void multiplyMatrix(unsigned long long m1[2][2], unsigned long long m2[2][2]){
    // Get matrix values
    unsigned long long m100 = m1[0][0];
    unsigned long long m101 = m1[0][1];
    unsigned long long m110 = m1[1][0];
    unsigned long long m111 = m1[1][1];

    unsigned long long m200 = m2[0][0];
    unsigned long long m201 = m2[0][1];
    unsigned long long m210 = m2[1][0];
    unsigned long long m211 = m2[1][1];

    // Store results in the first matrix
    m1[0][0] = (m100 * m200 + m101 * m210)%modulo;
    m1[0][1] = (m100 * m201 + m101 * m211)%modulo;
    m1[1][0] = (m110 * m200 + m111 * m210)%modulo;
    m1[1][1] = (m110 * m201 + m111 * m211)%modulo;
}

// Raise matrix to power n
void matpow(unsigned long long m1[2][2], unsigned long long n){
    // Constant array used for multiplying
    unsigned long long constant[2][2] = {{1,1}, {1,0}};

    // Recursively calls matpow to calculate exponent in logarithmic time
    if (n == 0 || n == 1) return;
    matpow(m1, n/2);
    multiplyMatrix(m1, m1);

    // Makes up for rounding error
    if (n % 2 == 1){
        multiplyMatrix(m1, constant);
    }
}

// Calculated the nth fibonacci number, modulo 10^9 + 7
unsigned long long fib(unsigned long long m1[2][2], unsigned long long n){
    matpow(m1, n-1);
    return m1[0][0];
}

//Fibonacci sequence using matrix exponentiation
int main() {
    unsigned long long n;
    cin >> n;
    // Array to be modified
    unsigned long long fibMatrix[2][2] = {{1,1}, {1,0}};
    cout << fib(fibMatrix, n) << endl;
}