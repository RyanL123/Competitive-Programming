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

const int MAXN = 1e6+10;
ll diff[MAXN];
ll cups[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, l;
    cin >> n >> t;
    for (int i = 0; i < t; i++){
        int a, b, c;
        cin >> a >> b >> c;
        diff[a]+=c; diff[b+1]-=c;
    }
    cin >> l;
    cups[1] = diff[1];
    for (int i = 2; i <= n; i++){
        cups[i] = cups[i-1] + diff[i];
    }
    ll ans = 0, sum = cups[1], lPtr = 1, rPtr = 1;
    while (lPtr <= n){
        while (rPtr+1 <= n && sum + cups[rPtr+1] <= l){
            sum += cups[rPtr+1];
            rPtr++;
        }
        if (rPtr-lPtr+1 > ans && lPtr != rPtr) ans = rPtr-lPtr+1;
        sum -= cups[lPtr];
        lPtr++;
    }
    cout << ans;
}