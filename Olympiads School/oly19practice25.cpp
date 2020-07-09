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

const int MM = 5e3+5;
ll d[MM][MM], m, n, k, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0, x1, y1, x2, y2; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        d[x1][y1]++, d[x1][y2+1]--, d[x2+1][y1]--, d[x2+1][y2+1]++;  
    }
    for (int i = 1; i < MM; i++){
        for (int j = 1; j < MM; j++){
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + d[i][j];
        }
    }
    for (int i = 1; i < MM; i++){
        for (int j = 1; j < MM; j++){
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + d[i][j];
        }
    }
    cin >> q;
    for (int i = 0, x1, y1, x2, y2; i < q; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout <<  d[x2][y2] - d[x2][y1-1] - d[x1-1][y2] + d[x1-1][y1-1] << '\n';
    }
}