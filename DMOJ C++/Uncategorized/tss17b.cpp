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

const int MM = 1414214+5;
int d[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        ld x, y;
        cin >> x >> y;
        int dis = ceil(sqrt(x*x + y*y));
        if (dis >= MM) continue;
        d[dis]++;
        d[MM-1]--;
    }
    for (int i = 1; i < MM; i++){
        d[i] += d[i-1];
    }
    for (int i = 0, r; i < q; i++){
        cin >> r;
        cout << d[r] << '\n';
    }
}