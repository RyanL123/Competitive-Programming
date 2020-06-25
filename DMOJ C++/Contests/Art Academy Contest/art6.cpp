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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double n, l, r, x, y;
    cin >> n >> l >> r >> x >> y;
    long double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2){
        cout << r-l;
    }
    else {
        long double intX1, intX2;
        if (x1 == x) intX1 = x;
        else{
            long double m1 = (y1-y)/(x1-x);
            long double b1 = y1-m1*x1;
            intX1 = -b1/m1;
        }
        if (x2 == x) intX2 = x;
        else {
            long double m2 = (y2-y)/(x2-x);
            long double b2 = y2-m2*x2;
            intX2 = -b2/m2;
        }
        long double left = min(intX1, intX2);
        long double right = max(intX1, intX2);
        cout << setprecision(9) << r - l - (min(right, r) - max(left, l));
    }
}