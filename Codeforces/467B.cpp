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
    int n, m, k, f, ans = 0;
    cin >> n >> m >> k;
    vi vec;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        vec.pb(x);
    }
    cin >> f;
    for (int i = 0; i < m; i++){
        int x = vec[i] ^ f;
        int cnt = 0;
        while (x > 0){
            x -= pow(2, floor(log2(x)));
            cnt++;
        }
        if (cnt <= k) ans++;
    }
    cout << ans;
}
