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

ll op[500010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++){
        int Q;
        cin >> Q;
        if (Q == 1){
            int x;
            cin >> x;
            op[x]++;
        }
        else if (Q == 2){
            int x;
            cin >> x;
            op[x]--;
        }
        else {
            int l, r, c, count = 0;
            cin >> l >> r >> c;
            for (int j = l; j <= r; j++){
                if (op[j] == c) count++;
            }
            cout << count << endl;
        }
    }
}