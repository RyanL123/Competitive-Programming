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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        int a[n+1];
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int mx = 0, cnt = 0, L = 1;
        for (int l = 1, r = 1; r <= n; r++){
            if (r-l+1 > k){
                if (a[l] < a[l+1] && a[l+1] > a[l+2]) cnt--;
                l++;
                r--;
            }
            if (r+1 <= n && r-1 >= 1 && r+1-l+1 <= k && a[r] > a[r+1] && a[r] > a[r-1]){
                cnt++;
            }
            if (r-l+1 == k && cnt > mx){
                mx = cnt; L = l;
            }
        }
        cout << mx+1 << " " << L << "\n";
    }
}