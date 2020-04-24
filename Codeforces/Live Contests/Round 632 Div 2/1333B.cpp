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
        int n;
        cin >> n;
        int a[n], b[n];
        map<int, bool> m;
        bool possible = true;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        for (int i = 0; i < n; i++){
            if (a[i] < b[i] && !m[1]){
                possible = false;
                break;
            }
            else if (a[i] > b[i] && !m[-1]){
                possible = false;
                break;
            }
            if (a[i] == -1) m[-1] = true;
            if (a[i] == 1) m[1] = true;
        }
        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }
}