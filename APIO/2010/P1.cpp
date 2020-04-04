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

ll psa[1000010], dp[1000010], n, A, B, C;

struct line{
    ll m, b;
    ll eval(ll x){
        return m*x+b;
    }
};

ll intX(line u, line v){
    return (u.b-v.b)/(v.m-u.m);
}

ll sq(ll a){
    return a*a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> A >> B >> C;
    for (int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    deque<line> dq;
    dp[1] = A*sq(psa[1]) + B*psa[1] + C;
    dq.push_back({0, 0});
    for (int i = 1; i <= n; i++){
        ll best = 0;
        while (dq.size() >= 2 && dq[1].eval(psa[i]) >= dq[0].eval(psa[i])){
            dq.pop_front();
        }
        best = dq[0].eval(psa[i]);
        dp[i] = best + A*sq(psa[i]) + B*psa[i] + C;
        line cur = {
                -2*A*psa[i],
                A*sq(psa[i])-B*psa[i]+dp[i]
        };
        while(dq.size()>= 2 && intX(cur, dq[dq.size()-2]) < intX(dq[dq.size()-1], dq[dq.size()-2])){
            dq.pop_back();
        }
        dq.push_back(cur);
    }
    cout << dp[n];
}