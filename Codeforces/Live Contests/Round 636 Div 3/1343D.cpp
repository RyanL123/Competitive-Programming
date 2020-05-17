#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int freq[400005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        int a[n+1];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n/2; i++){
            freq[a[i] + a[n-1-i]]++;
        }
        int diff[k*2+5];
        memset(diff, 0, sizeof(diff));
        for (int i = 0; i < n/2; i++){
            diff[min(a[i], a[n-1-i])+1]++;
            diff[max(a[i], a[n-1-i])+k+1]--;
        }
        for (int i = 1; i <= k*2; i++){
            diff[i] += diff[i-1];
        }
        int ans = inf;
        for (int i = 2; i <= 2*k; i++) ans = min(ans, diff[i] - freq[i] + (n/2 - diff[i])*2);
        cout << ans << '\n';
    }
}