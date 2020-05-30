#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

const int MM = 1e4;
int bit[MM][MM], A[MM];

void upd(int x, int y, int val){
    for (int i = x; i < MM; i += (i&-i)){
        for (int j = y; j < MM; j += (j&-j)){
            bit[i][j] += val;
        }
    }
}

int qry(int x, int y){
    int ret = 0;
    for (int i = x; i; i -= (i&-i)){
        for (int j = y; j; j-= (j&-j)){
            ret += bit[i][j];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        x++;
        A[i] = x;
        upd(i, x, 1);
    }
    int Q;
    cin >> Q;
    while (Q--){
        int q;
        cin >> q;
        if (q == 1){
            int i, j, a, b;
            cin >> i >> j >> a >> b;
            j++, b++;
            int w = qry(j, b), x = qry(i, b), y = qry(j, a), z = qry(i, a);
            cout << w - x - y + z << "\n";
        }
        else {
            int i, h;
            cin >> i >> h;
            i++, h++;
            upd(i, A[i], -1);
            A[i] = h;
            upd(i, h, 1);
        }
    }
}
