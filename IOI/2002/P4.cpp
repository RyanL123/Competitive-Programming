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

const int MM = 1e4+5;

int dp[MM], T[MM], F[MM], pf[MM], pt[MM], n, s;
int f(int j, int k){
    return (dp[k]-dp[j])/(pt[k]-pt[j]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> T[i] >> F[i];
    }
    for (int i = n; i >= 1; i--){
        pf[i] = pf[i+1] + F[i];
        pt[i] = pt[i+1] + T[i];
    }
    deque<int> dq;
    dq.pb(n+1);
    for (int i = n; i >= 1; i--){
        while (dq.size() >= 2 && f(dq[0], dq[1]) < pf[i]){
            dq.pop_front();
        }
        dp[i] = dp[dq[0]] + (s+pt[i]-pt[dq[0]])*pf[i];
        while (dq.size() >= 2 && f(dq[dq.size()-2], dq[dq.size()-1]) > f(dq[dq.size()-1], i)){
            dq.pop_back();
        }
        dq.pb(i);
    }
    cout << dp[1] << '\n';
}