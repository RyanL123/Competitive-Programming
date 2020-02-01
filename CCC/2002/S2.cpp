#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == 0){
        cout << 0;
    }
    else if (a%b == 0){
        cout << a/b;
    }
    else {
        int c = 0;
        while (true){
            if (a - b < 0){
                break;
            }
            else {
                a -= b;
                c++;
            }
        }
        int gcd = __gcd(a, b);
        a/=gcd;
        b/=gcd;
        if (c){
            cout << c << " " << a << "/" << b;
        }
        else {
            cout << a << "/" << b;
        }
    }
}