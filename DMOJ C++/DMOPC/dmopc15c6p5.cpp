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

const int MM = 3e6+5;
int a[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    deque<int> mn, mx;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int l = 1, r = 1; r <= n; r++){
        while (!mx.empty() && mx.back() < a[r]) mx.pop_back();
        mx.pb(a[r]);
        while (!mn.empty() && mn.back() > a[r]) mn.pop_back();
        mn.pb(a[r]);
        while (mx.front() - mn.front() > k){
            if (!mx.empty() && mx.front() == a[l]) mx.pop_front();
            if (!mn.empty() && mn.front() == a[l]) mn.pop_front();
            l++;
        }
        ans += r-l+1;
    }
    cout << ans << '\n';
}