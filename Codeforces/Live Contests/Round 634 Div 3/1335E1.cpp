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

int sum(int c, int l, int r, int pre[27][2010]){
    return pre[c][r+1] - pre[c][l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n+1];
        int pre[27][2010];
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            for (int j = 0; j < 26; j++) pre[j][i] += pre[j][i-1];
            pre[a[i]-1][i]++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) ans = max(ans, pre[i][n]);
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int mid = 0, out = 0;
                for (int k = 0; k < 26; k++){
                    mid = max(mid, sum(k, i, j, pre));
                    out = max(out, min(sum(k, 0, i-1, pre), sum(k, j+1, n-1, pre)));
                }
                ans = max(ans, 2*out+mid);
            }
        }
        cout << ans << '\n';
    }
}