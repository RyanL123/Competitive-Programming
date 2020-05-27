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
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = inf;
        for (int i = 1; i <= sqrt(n)+1; i++){
            if (n%i==0){
                if (n/i <= k){
                    ans = min(ans, i);
                }
                if (i <= k){
                    ans = min(ans, n/i);
                }
            }
        }
        cout << ans << "\n";
    }
}
