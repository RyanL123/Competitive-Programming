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

const int MM = 1e3+5;
bool f[MM][MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            char C;
            cin >> C;
            if (C == 'X') {
                f[i][j] = true;
                for (int k = 1; k <= c; k++) f[i][k] = true;
                for (int k = 1; k <= r; k++) f[k][j] = true;
            }
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0, x, y; i < Q; i++){
        cin >> x >> y;
        cout << (f[y][x]?"Y":"N") << '\n';
    }
}