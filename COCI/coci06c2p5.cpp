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

const int MM = 405;
int a[MM][MM];

int calc(int r, int c1, int c2){
    return a[r][c2] - a[r][c1-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            char C;
            cin >> C;
            a[i][j] = (C=='X');
            a[i][j] += a[i][j-1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= c; i++){
        for (int j = i; j <= c; j++){
            int cur = 0;
            for (int k = 1; k <= r; k++){
               if (calc(k, i, j) != 0) cur = 0;
               else {
                   cur++;
                   ans = max(ans, ((j-i+1)+cur)*2);
               }
            }
        }
    }
    cout << ans-1 << "\n";
}