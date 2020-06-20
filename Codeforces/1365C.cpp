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
    int n, ans = 1;
    cin >> n;
    int a[n], b[n], frq[n+1];
    memset(frq, 0, sizeof(frq));
    map<int, int>m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        m[a[i]] = i;
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        int pos = m[b[i]];
        if (pos >= i) frq[pos-i]++;
        else frq[n-i+pos]++;
    }
    for (int i = 0; i <= n; i++){
        ans = max(ans, frq[i]);
    }
    cout << ans << '\n';
}