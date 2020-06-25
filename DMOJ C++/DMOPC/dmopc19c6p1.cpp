#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    long double x1, y1, x2, y2, x3, x4, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (x2 == x1){
        if (x4 == x3){
            if (x2 == x4) {
                cout << "coincident";
                return 0;
            }
            else {
                cout << "parallel";
                return 0;
            }
        }
        long double s2 = (y4-y3)/(x4-x3);
        long double yINT2 = y3-s2*x3;
        long double intY = x1*s2+yINT2;
        printf("%Lf %Lf", x1, intY);
        return 0;
    }
    else if (x4 == x3){
        if (x1 == x2){
            if (x2 == x4) {
                cout << "coincident";
                return 0;
            }
            else {
                cout << "parallel";
                return 0;
            }
        }
        long double s1 = (y2-y1)/(x2-x1);
        long double yINT1 = y1-s1*x1;
        long double intY = x3*s1+yINT1;
        printf("%Lf %Lf", x3, intY);
        return 0;
    }
    long double s1 = (y2-y1)/(x2-x1), s2 = (y4-y3)/(x4-x3);
    long double yINT1 = y1-s1*x1, yINT2 = y3-s2*x3;
    if (abs(s1 - s2) < 1e-7 && abs(yINT1 - yINT2) < 1e-7){
        cout << "coincident";
    }
    else if (abs(s1 - s2) < 1e-7 ) {
        cout << "parallel";
    }
    else {
        long double intX = (yINT1 - yINT2)/(s2-s1);
        long double intY = intX*s1+yINT1;
        printf("%Lf %Lf", intX, intY);
    }
}