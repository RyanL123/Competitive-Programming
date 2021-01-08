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

int M, Q, T[105], dp[105], backtrack[105];
string ppl[105];

int mx(int st, int ed) {
    int ret = 0;
    for (int i = st; i <= ed; i++) ret = max(ret, T[i]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> Q;
    for (int i = 1; i <= Q; i++) cin >> ppl[i] >> T[i];
    for (int i = 1; i <= M; i++) {
        dp[i] = max(dp[i-1], T[i]);
        backtrack[i] = i;
    }
    for (int i = M+1; i <= Q; i++) {
        int best = inf, ind;
        for (int j = 0; j < M; j++) {
            int cur = mx(i-j, i)+dp[i-j-1];
            if (cur <= best) {
                best = cur;
                ind = i-j-1;
            }
        }
        dp[i] = best, backtrack[i] = ind;
    }
    cout << "Total Time: " << dp[Q] << '\n';
    vi order;
    int cur = Q;
    while (true) {
        if (cur == backtrack[cur]) {
            order.pb(cur);
            break;
        }
        order.pb(cur);
        cur = backtrack[cur];
    }
    reverse(all(order));
    int prev = 1;
    for (int i : order) {
        for (int j = prev; j <= i; j++) cout << ppl[j] << ' ';
        prev = i+1;
        cout << '\n';
    }
}