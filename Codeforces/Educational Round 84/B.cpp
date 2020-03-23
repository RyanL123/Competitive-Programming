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
vi noMatch;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, cnt = 0;
        cin >> n;
        for (int i = 0; i <= 100000; i++){
            taken[i] = false;
        }
        noMatch.clear();
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
            if (!flag) noMatch.pb(i);
        }
        if (cnt == n) cout << "OPTIMAL\n";
        else {
            bool improve = false;
            int last = 1;
            for (int i = 0; i < noMatch.size(); i++){
                if (improve) break;
                for (; last <= n; last++){
                    if (!taken[last]){
                        if (!improve) cout << "IMPROVE\n";
                        taken[last] = true;
                        cout << noMatch[i] << " " << last << "\n";
                        improve = true;
                        break;
                    }
                }
            }
            if (!improve) cout << "OPTIMAL\n";
        }
    }
}