/*
ID: ryan.li2
TASK: friday
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

bool odd(int m){
    return m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12;
}
bool leap(int y){
    if (y % 100 == 0 && y % 400 == 0) return true;
    if (y % 100 == 0 && y % 400 != 0) return false;
    return y % 4 == 0;
}

int ans[8];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("friday.in", "r", stdin);
    int n;
    cin >> n;
    int y = 1900, m = 1, d = 1, cnt = 1;
    while (!(y == 1900+n-1 && m == 12 && d == 31)){
        if (d == 13) ans[cnt]++;
        cnt++;
        if (cnt == 8) cnt = 1;
        d++;
        if ((d > 28 && m == 2 && !leap(y)) || (d > 29 && m == 2 && leap(y)) || (d > 31 && odd(m)) || (d > 30 && !odd(m))){
            d = 1;
            m++;
        }
        if (m > 12){
            y++;
            m = 1;
        }
    }
    freopen("friday.out", "w", stdout);
    cout << ans[6] << " " << ans[7] << " ";
    for (int i = 1; i <= 5; i++){
        cout << ans[i];
        if (i == 5) cout << "\n";
        else cout << " ";
    }
}