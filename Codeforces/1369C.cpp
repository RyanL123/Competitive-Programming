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
        int n, k;
        cin >> n >> k;
        int a[n+1], w[k+1], c[k+1];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < k; i++){
            cin >> w[i];
            c[i] = -1;
        }
        sort(a, a+n);
        sort(w, w+k);
        int ptr = 0;
        ll ans = 0;
        for (int i = n-1; i > n-k-1; i--){
            ans += a[i];
            if (w[ptr] == 1) ans += a[i];
            w[ptr]--;
            ptr++;
            if (ptr > k-1) ptr = 0;
        }
        for (int i = n-k-1; i >= 0; i--){
            while (w[ptr] <= 0){
                ptr++;
                if (ptr > k-1) ptr = 0;
            }
            if (w[ptr] == 1){
                ans += a[i];
            }
            w[ptr]--;
        }
        cout << ans << '\n';
    }
}