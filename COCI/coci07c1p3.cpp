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

vi v;
int mn = 0, num = 0, a, b;

void solve(int x){
    if (x >= a && x <= b){
        int ans = inf;
        for (int i : v){
            ans = min(ans, abs(x - i));
        }
        if (ans > mn){
            mn = ans;
            num = x;
        }
    }
}

pii f(int x){
    if (x%2 == 0) return {x-1, x+1};
    return {x, x};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.pb(x);
    }
    srt(v);
    cin >> a >> b;
    for (int i = 0; i < n-1; i++){
        pii p = f((v[i]+v[i+1])/2);
        solve(p.first);
        solve(p.second);
    }
    pii A = f(a), B = f(b);
    solve(A.second);
    solve(B.first);
    cout << num << '\n';
}