#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double quadFormula(double a, double b, double c, double upper, double lower){
    double answer1 = (-b + (sqrt(pow(b,2) - 4.0*a*c)))/(2.0*a);
    double answer2 = (-b - (sqrt(pow(b,2) - 4.0*a*c)))/(2.0*a);
    if (lower <= answer1 && answer1 <= upper){
        return answer1;
    }
    return answer2;
}
int main() {
    int n, m;
    double a, b;
    int eq1 [6] {0};
    int eq2 [6] {0};
    double eq3 [6];
    cin >> n;
    for (int i = n; i >= 0; i--){
        cin >> eq1[i];
    }
    cin >> m;
    for (int i = m; i >= 0; i--){
        cin >> eq2[i];
    }
    for (int i = 0; i < 6; i++){
        eq3[i] = eq2[i] - eq1[i];
    }
    cin >> a >> b;

    if (eq3[2] != 0){
        printf("%.9f", quadFormula(eq3[2], eq3[1], eq3[0], b, a));
    }
    else {
        double answer = -eq3[0]/eq3[1];
        printf("%.9f", answer);
    }
}