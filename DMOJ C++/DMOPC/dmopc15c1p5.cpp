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

const int MM = 600;
int a[MM][MM];

int calc(int x1, int y1, int x2, int y2){
    return a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h, n;
    cin >> w >> h >> n;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            cin >> a[i][j];
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            for (int k = 1; k <= max(w, h); k++){
                int L = floor((double)n/k);
                ans = max(ans, calc(i, j, min(h, i+k-1), min(w, j+L-1)));
                ans = max(ans, calc(i, j, min(h, i+L-1), min(w, j+k-1)));
            }
        }
    }
    cout << ans << '\n';
}