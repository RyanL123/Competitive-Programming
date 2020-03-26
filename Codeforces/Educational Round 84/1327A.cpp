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
    int t;
    cin >> t;
    while (t--){
        ull n, k;
        cin >> n >> k;
        if (n < k*k) cout << "NO\n";
        // Diff parity
        else if ((n-k) % 2 != 0) cout << "NO\n";
        else cout << "YES\n";
    }
}