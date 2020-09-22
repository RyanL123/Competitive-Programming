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
        ull n, tot = 0, cur = 0, sq = 1;
        cin >> n;
        int cnt = 0;
        while (tot < n) {
            cnt++;
            cur *= 2;
            cur += sq*sq;
            sq *= 2;
            tot += cur;
        }
        if (tot > n) cnt--;
        cout << cnt << '\n';
    }
}