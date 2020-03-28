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

int freq[1000010], a[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, cnt = 0;
    ll ans = 0;
    cin >> n >> k;
    for (int l = 0, r = 0; r < n; r++){
        cin >> a[r];
        freq[a[r]]++;
        if (freq[a[r]] == 1) cnt++;
        while (cnt >= k) {
            ans += n-r;
            freq[a[l]]--;
            if (freq[a[l]] == 0) cnt--;
            l++;
        }
    }
    cout << ans;
}