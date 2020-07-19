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

bool solve(int a[], int l1, int l2, int n){
    int frq[n+1];
    memset(frq, 0, sizeof(frq));
    bool flag = true;
    for (int i = 1; i <= l1; i++) frq[a[i]]++;
    for (int i = 1; i <= l1; i++) flag &= (frq[i] == 1);
    memset(frq, 0, sizeof(frq));
    for (int i = l1+1; i <= n; i++) frq[a[i]]++;
    for (int i = 1; i <= l2; i++) flag &= (frq[i] == 1);
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n+1], mx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mx = max(a[i], mx);
        }
        vii ans;
        int l1 = mx, l2 = n-mx;
        if (solve(a, l1, l2, n)) {
            ans.eb(l1, l2);
        }
        swap(l1, l2);
        if (solve(a, l1, l2, n) && l1 != l2) {
            ans.eb(l1, l2);
        }
        cout << ans.size() << '\n';
        for (pii p : ans) cout << p.first << ' ' << p.second << '\n';
    }
}