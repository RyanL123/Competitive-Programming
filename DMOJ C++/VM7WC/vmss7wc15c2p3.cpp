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
    ll n, h, ans = 0;
    cin >> n;
    stack<pair<ll, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (s.empty()) s.push({h, 0});
        else if (h < s.top().first) {
            s.push({h, 1});
            ans++;
        }
        else if (h == s.top().first) {
            s.top().second++;
            ans+=s.top().second;
        }
        else {
            while (!s.empty() && h > s.top().first) {
                ans += max(1, s.top().second);
                s.pop();
            }
            if (s.empty()) {
                s.push({h, 0});
            }
            else if (s.top().first == h) {
                s.top().second++;
                ans+=max(1, s.top().second);
            }
            else {
                s.push({h, 1});
                ans++;
            }
        }
    }
    cout << ans << '\n';
}