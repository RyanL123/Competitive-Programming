#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vi v;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            v.pb(x);
        }
        srt(v);
        int ans = inf;
        for (int i = 0; i < n-1; i++){
            ans = min(ans, v[i+1]-v[i]);
        }
        cout << ans << '\n';
    }
}
