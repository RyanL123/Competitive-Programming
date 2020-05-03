#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f
const int MM = 2e5+5, LOG = 18;
int N, Q;
ll st[LOG][MM], val;
ll rmq(int l, int r){
    int lvl = log2(r-l+1);
    return min(st[lvl][l], st[lvl][r-(1<<lvl)+1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++){
        cin >> st[0][i];
    }
    // Build sparse table
    // Can also be done with seg tree
    for (int i = 1; i < LOG; i++){
        for (int j = 1; j + (1<<i)-1 <= N; j++){
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    for (int i = 1; i <= Q; i++){
        int l, r;
        cin >> val >> l >> r;
        while (true){
            int lo = l, hi = r, pos = 0;
            /* Binary search for first element less than val
               Prioritize left side of array in binary search
               Afterwards, mod val and continue until no elements are less than it
               Elements greater than val do not affect the mod and can be ignored
               Otherwise, the remainder is guaranteed to be less than val/2
               This operations has to be performed at most log n times over the interval [L, R] */
            while (lo <= hi){
                int m = (lo+hi)/2;
                if (rmq(l, m) <= val) {
                    pos = m;
                    hi = m - 1;
                }
                else lo = m+1;
            }
            if (pos == 0) break;
            val %= st[0][pos];
            l = pos+1;
        }
        cout << val << '\n';
    }
}
