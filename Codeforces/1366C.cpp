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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        int mat[n][m], frq[60][2];
        memset(frq, 0, sizeof(frq));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> mat[i][j];
                frq[i+j][mat[i][j]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i <= n+m-2; i++){
            int j = n-1+m-1-i;
            if (i <= j) continue;
            ans += min(frq[i][1]+frq[j][1], frq[i][0]+frq[j][0]);
        }
        cout << ans << '\n';
    }
}