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

int cnt[100010];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q, q, prev = 0;
    cin >> Q;
    while (Q--){
        cin >> q;
        if (q == 1){
            prev++;
            cnt[prev]++;
        }
        else if (q == 2){
            cnt[prev]++;
        }
        else {
            int x;
            cin >> x;
            int total = 0, i = 0;
            for (i = 0; i <= x; i++){
                if (total + cnt[i] > x){
                    break;
                }
                total += cnt[i];
            }
            if (total == x) cout << "1\n";
            else {
                int ans = total + cnt[i] - x;
                if (ans % 2 == 0) cout << "1\n";
                else cout << "0\n";
            }
        }
    }
}