#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int main() {
    int n, x, y, left = 200, right = 0, top = 0, bottom = 200;
    scanf("%d", &n);
    while (n--){
        scanf("%d,%d", &x, &y);
        if (x < left){
            left = x;
        }
        if (x > right){
            right = x;
        }
        if (y > top){
            top = y;
        }
        if (y < bottom){
            bottom = y;
        }
    }
    printf("%d,%d\n", min(left-1, right+1), min(bottom-1, top+1));
    printf("%d,%d\n", max(left-1, right+1), max(bottom-1, top+1));
}
