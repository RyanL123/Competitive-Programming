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

const int MM = 3e3+5;

int bit[MM][MM], tri[MM][MM];

void upd(int x, int y, int val){
    for (int i = x; i < MM; i += (i&-i)){
        for (int j = y; j < MM; j += (j&-j)){
            bit[i][j] = max(bit[i][j], val);
        }
    }
}

int qry(int x, int y){
    int ret = 0;
    for (int i = x; i; i -= (i&-i)){
        for (int j = y; j; j -= (j&-j)){
            ret = max(ret, bit[i][j]);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cin >> tri[i][j+n-i];
        }
    }
    ll ans = 0;
    for (int i = n; i > 0; i--){
        for (int j = 0; j+i <= n; j++){
            int x = n-j, y = i+j;
            upd(x, y, tri[y][x]);
        }
        for (int j = 0; j+i <= n; j++){
            int x = n-j, y = i+j;
            if (x+k-1 <= n) ans += qry(x+k-1, y);
        }
    }
    cout << ans << '\n';
}