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

const int MM = 1e6+5;
int h[MM], cnt[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    stack<pii> s;
    for (int i = n; i >= 1; i--) {
        if (s.empty()) s.push({h[i], i});
        else {
            while (!s.empty() && h[i] > s.top().first) {
                cnt[s.top().second] = s.top().second - i;
                s.pop();
            }
            s.push({h[i], i});
        }
    }
    while (!s.empty()) {
        cnt[s.top().second] = s.top().second-1;
        s.pop();
    }

    for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
}