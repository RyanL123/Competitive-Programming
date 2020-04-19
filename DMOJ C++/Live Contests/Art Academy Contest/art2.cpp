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

ll m = pow(2,32);
map<ll, ll> d;

ll f (int j){
    return (j * 2654435761) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cnt = 0;
    vi ans;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        ll p;
        cin >> p;
        if (d[p]) ans.pb(d[p]);
        else{
            int j = 0;
            while (true){
                if (f(j) == p) {
                    ans.pb(j);
                    d[p] = j;
                    break;
                }
                else if (f(m-j) == p){
                    ans.pb(m-j);
                    d[p] = m-j;
                    break;
                }
                j++;
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < m; i++){
        cnt += ans[n-1-i];
    }
    cout << cnt;
}