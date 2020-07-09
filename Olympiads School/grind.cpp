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

const int MM = 1e7+5;
int d[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0, s, f; i < n; i++){
        cin >> s >> f;
        d[f]--;
        d[s]++;
    }
    int ans = 0;
    for (int i = 1; i < MM; i++){
        d[i] += d[i-1];
        ans = max(ans, d[i]);
    }
    cout << ans << '\n';
}