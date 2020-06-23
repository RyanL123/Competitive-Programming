#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

const int MM = 1e5+5;
int b[MM], pfx[MM], t, ans;

bool solve(int i, int m){
    return pfx[i+m]-pfx[i-1] <= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> t;
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        pfx[i] = pfx[i-1] + b[i];
    }
    for (int i = 1; i <= n; i++){
        int l = 0, r = n-i+1;
        while (l < r){
            int m = (l+r)/2;
            if (solve(i, m)) l = m+1;
            else r = m;
        }
        ans = max(ans, r);
    }
    cout << ans << '\n';
}