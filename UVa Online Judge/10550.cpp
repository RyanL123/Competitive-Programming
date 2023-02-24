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
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        if (a + b + c + d == 0) return 0;
        int res = 360*3;
        if (b > a) res += (40-b+a)*9;
        else res += (a-b)*9;
        if (c < b) res += (40-b+c)*9;
        else res += (c-b)*9;
        if (c > d) res += (c-d)*9;
        else res += (c+40-d)*9;
        cout << res << endl;
    }
}