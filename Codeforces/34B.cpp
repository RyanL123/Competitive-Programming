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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ans = 0;
    cin >> n >> m;
    vi p;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x <= 0) p.pb(-x);
    }
    sort(p.begin(), p.end());
    for (int i = p.size()-1; i >= max(0, (int)p.size()-m); i--){
        ans += p[i];
    }
    cout << ans;
}