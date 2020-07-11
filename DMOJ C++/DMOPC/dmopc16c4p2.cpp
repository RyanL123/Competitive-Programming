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

const int MM = 1e5+5;
int F[MM], E[MM], P[MM], B, f;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> B;
    for (int i = 0; i < B; i++){
        cin >> F[i] >> E[i] >> P[i];
    }
    cin >> f;
    vi T;
    for (int i = 0, t; i < f; i++) {
        cin >> t;
        T.pb(t);
    }
    srt(T);
    int ans = 0;
    for (int i = 0; i < B; i++){
        int s = distance(T.begin(), lower_bound(T.begin(), T.end(), F[i]));
        int e = distance(T.begin(), upper_bound(T.begin(), T.end(), E[i]))-1;
        if (s > e) ans += P[i];
    }
    cout << ans << '\n';
}