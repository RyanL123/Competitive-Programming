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

bool taken[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, cnt = 0;
        cin >> n;
        for (int i = 0; i <= n; i++){
            taken[i] = false;
        }
        int noMatch;
        for (int i = 1; i <= n; i++){
            int k, g;
            bool flag = false;
            cin >> k;
            for (int j = 0; j < k; j++){
                cin >> g;
                if (!taken[g] && !flag){
                    taken[g] = true;
                    flag = true;
                    cnt++;
                }
            }
            if (!flag) noMatch = i;
        }
        if (cnt == n) cout << "OPTIMAL\n";
        else {
            cout << "IMPROVE\n";
            for (int i = 1; i <= n; i++){
                if (!taken[i]){
                    cout << noMatch << " " << i << "\n";
                    break;
                }
            }
        }
    }
}