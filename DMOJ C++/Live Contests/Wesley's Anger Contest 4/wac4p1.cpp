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

bool cmp(int a, int b){
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vi v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.pb(x);
    }
    for (int i = 0; i < q; i++){
        int Q;
        cin >> Q;
        if (Q == 1){
            int l, r;
            cin >> l >> r;
            sort(v.begin()+l-1, v.begin()+r);
        }
        else {
            int l, r;
            cin >> l >> r;
            sort(v.begin()+l-1, v.begin()+r, cmp);
        }
    }
    for (int i = 0; i < n; i++){
        if (i == n-1) cout << v[i] << '\n';
        else cout << v[i] << " ";
    }
}