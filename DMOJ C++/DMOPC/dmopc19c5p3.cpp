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
    ull h, v;
    cin >> h >> v;
    ull ans = ((h*(h-1))/2)*((v*(v-1))/2);
    for (int y = 1; y <= h; y++){
        for (int x = 1; x <= v; x++){
            int g = __gcd(x, y);
            int dy = y/g;
            int dx = x/g;
            for (int r = y+dx, c = x+dy; r <= h && c <= v; r+=dx, c+=dy){
                ans += (h-r)*(v-c);
            }
        }
    }
    cout << ans;
}