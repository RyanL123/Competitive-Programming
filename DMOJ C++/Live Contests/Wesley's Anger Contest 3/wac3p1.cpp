#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t, d, p;
    bool cT = false;
    bool cD = false;
    bool cP = false;
    cin >> t >> d >> p;
    if (t < -40){
        cT = true;
    }
    if (d >= 15){
        cD = true;
    }
    if (p > 50){
        cP = true;
    }
    if (cT && cD){
        cout << "YES";
    }
    else if (cD && cP){
        cout << "YES";
    }
    else if (cP && cT){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
