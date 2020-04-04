#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

ll h[200010], dp[200010];

struct line{
    ll m, b;
    ll eval(ll x){
        return m*x+b;
    }
};

ll intX(line u, line v){
    return (u.b-v.b)/(v.m-u.m);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
    }
    deque<line> dq;
    dq.push_back({-2*h[1],dp[1]+h[1]*h[1]});
    for (int i = 2; i <= n; i++){
        while (dq.size() >= 2 && dq[1].eval(h[i]) < dq[0].eval(h[i])){
            dq.pop_front();
        }
        dp[i] = dq[0].eval(h[i]) + c + h[i] * h[i];
        line cur = {
                -2*h[i],
                dp[i]+h[i]*h[i]
        };
        while (dq.size() >= 2 && intX(cur, dq[dq.size()-2]) < intX(dq[dq.size()-1], dq[dq.size()-2])){
            dq.pop_back();
        }
        dq.push_back(cur);
    }
    cout << dp[n];
}
