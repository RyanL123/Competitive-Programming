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
        int n, x;
        cin >> n >> x;
        int a[n+1];
        bool done = true;
        int tot = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i]%x!=0) done = false;
            tot += a[i];
        }
        if (done) cout << "-1\n";
        else if (tot%x!=0) cout << n << "\n";
        else {
            int l = 1, r = n;
            for (int i = 1; i <= n; i++){
                if (a[i]%x != 0){
                    l = i;
                    break;
                }
            }
            for (int i = n; i >= 1; i--){
                if (a[i]%x != 0){
                    r = i;
                    break;
                }
            }
            cout << n-min(l, n-r+1) << '\n';
        }
    }
}