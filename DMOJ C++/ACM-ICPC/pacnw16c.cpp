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

const int MM = 1e5+5;
bool c[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, r;
    cin >> n >> k >> r;
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        c[x] = true;
    }
    int ans = 0, cnt = 0;
    deque<int> dq;
    for (int i = 1; i < r; i++) {
        if (c[i]) cnt++;
        else dq.pb(i);
    }
    for (int i = r; i <= n; i++) {
        cnt -= c[i-r];
        if (c[i]) cnt++;
        else dq.pb(i);
        while (!dq.empty() && dq.front() < i-r) dq.pop_front();
        while (cnt < 2) {
            c[dq.back()] = true;
            dq.pop_back();
            cnt++;
            ans++;
        }
        
        
    }
    cout << ans << '\n';
}