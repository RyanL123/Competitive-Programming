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

const int MM = 1e5+5;
int diff[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        diff[r+1]--;
        diff[l]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
        if (diff[i]%2==1) ans++;
    }
    cout << ans << '\n';
}
