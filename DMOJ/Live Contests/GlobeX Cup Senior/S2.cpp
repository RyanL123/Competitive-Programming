#include <bits/stdc++.h>

using namespace std;

long double eq1 [6] {0};
long double eq2 [6] {0};
long double eq3 [6];

long double calc(long double x){
    long double y = 0;
    for (int i = 0; i < 6; i++){
        y += pow(x, i)*eq3[i];
    }
    return y;
}

bool cross(long double x1, long double x2){
    long double y1 = 0;
    long double y2 = 0;
    y1 = calc(x1);
    y2 = calc(x2);
    return (y1 > 0 && y2 < 0) || (y1 < 0 && y2 > 0);
}

int main() {
    int n, m;
    long double a, b;

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
    long double lo = a, hi = b;
    while (lo < hi){
        long double mid = (lo+hi)/2;
        if (calc(mid) <= 1e-8 && cross(mid-1e-8, mid+1e-8)){
            printf("%.10Lf", mid);
            return 0;
        }
        if (cross(lo, mid)){
            hi = mid;
        }
        else if (cross(mid, hi)){
            lo = mid;
        }
        if (calc(lo) == 0){
            printf("%.10Lf", lo);
            return 0;
        }
        else if (calc(hi) == 0){
            printf("%.10Lf", hi);
            return 0;
        }
    }
}