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
    int t;
    cin >> t;
    while (t--){
        int n;
        set<int> s;
        cin >> n;
        int cnt[n+1];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            s.insert(x);
            cnt[x]++;
        }
        int ans = 0, dist = s.size();
        for (int i = 0; i <= n; i++){
            ans = max(ans, min(cnt[i]-1, dist));
            ans = max(ans, min(cnt[i], dist-1));
        }
        cout << ans << "\n";
    }
}