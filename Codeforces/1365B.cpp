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
        int a[n+1], b[n+1];
        bool done = true;
        a[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            done &= a[i] >= a[i-1];
        }
        bool flag = false;
        for (int i = 1; i <= n; i++){
            cin >> b[i];
            if (i > 1) flag |= b[i-1] != b[i];
        }
        if (done) cout << "Yes\n";
        else cout << (flag ? "Yes" : "No") << '\n';
    }
}