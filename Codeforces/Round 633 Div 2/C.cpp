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

int calc(int a, int b){
    int ret = 0, diff = b-a, cur = 0;
    while (diff > 0){
        diff -= pow(2, cur);
        ret++, cur++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, b = 0, mx = 0;
        cin >> n;
        cin >> b;
        for (int i = 1; i < n; i++){
            int a;
            cin >> a;
            b = max(a, b);
            mx = max(mx, calc(a, b));
        }
        cout << mx << "\n";
    }
}
