#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

struct line{
    ll m, b;
    ll eval(ll x){
        return m*x+b;
    }
};

int intX(line u, line v){
    return (u.b - v.b)/(v.m-u.m);
}

// Min cost to catch first N criminals
// Cost = min((p[i]-p[j])^2 + h + dp[j-1]) for all j <= i
// = p[i]^2 - 2*p[i]*p[j] + p[j]^2 + dp[j-1] + h
// p[i]^2 + h is constant for i
// therefore the equation can be simplified to -2*p[i]*p[j] + p[j]^2 + dp[j-1]
// m = -2*p[j]
// x = p[i]
// b = dp[j-1] + p[j]^2
ll dp[100010], p[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
    }
    deque<line> dq;
    dq.push_back({-2*p[1], dp[0]+p[1]*p[1]});
    dp[1] = h;
    for (int i = 2; i <= n; i++){
        while (dq.size() >= 2 && dq[1].eval(p[i]) < dq[0].eval(p[i])){
            dq.pop_front();
        }
        dp[i] = min(dq[0].eval(p[i]) + h + p[i]*p[i], h+dp[i-1]);
        line cur = {
                -2*p[i],
                dp[i-1]+p[i]*p[i]
        };
        while (dq.size() >= 2 && intX(cur, dq[dq.size()-2]) < intX(dq[dq.size()-1], dq[dq.size()-2])){
            dq.pop_back();
        }
        dq.push_back(cur);
    }
    cout << dp[n] << "\n";
}