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
        int n;
        cin >> n;
        int a[2*n+1];
        for (int i = 1; i <= 2*n; i++){
            cin >> a[i];
        }
        vii ans;
        bool done[2*n+1];
        for (int gcd = 2; gcd <= 1001; gcd++){
            ans.clear();
            memset(done, false, sizeof(done));
            for (int i = 1; i <= 2*n; i++){
                for (int j = i+1; j <= 2*n; j++){
                    if (ans.size() == n-1) goto done;
                    if (!done[i] && !done[j] && (a[i]+a[j])%gcd==0){
                        ans.eb(i, j);
                        done[i] = done[j] = true;
                        break;
                    }
                }
            }
            done:
            if (ans.size() == n-1){
                for (pii p : ans){
                    cout << p.first << ' ' << p.second << '\n';
                }
                break;
            }
        }
    }
}