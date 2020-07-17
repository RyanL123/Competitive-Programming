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

const int MM = 2e5+5;
ll a[MM], psa[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int i = 1; i <= 2*n; i++){
        psa[i] = psa[i-1] + a[i];
    }
    deque<pair<ll, ll>> dq;
    dq.pb({0, 0});
    for (int i = 1; i <= 2*n; i++){
        while (!dq.empty() && dq.back().second > psa[i]){
            dq.pop_back();
        }
        dq.pb({i, psa[i]});
        while (!dq.empty() && dq.front().first < i-k){
            dq.pop_front();
        }
        ans = max(ans, psa[i] - dq.front().second);
    }
    cout << ans << '\n';
}