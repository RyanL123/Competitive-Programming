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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, x, diff = 0, cnt = 0;
        cin >> n >> x;
        for (int i = 0, y; i < n; i++) {
            cin >> y;
            if (y == x) cnt++;
            diff += y-x;
        }   
        if (cnt == n) cout << "0\n";
        else if (cnt >= 1 || diff == 0) cout << "1\n";
        else cout << "2\n";
    }
}