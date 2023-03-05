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
        int n, k;
        string s;
        cin >> n >> k >> s;
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        int res = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int mx = max(m[c], m[toupper(c)]), mn = min(m[c], m[toupper(c)]);
            res += mn;
            res += max(0, min(k, (mx-mn)/2));
            k -= (mx-mn)/2;
        }
        cout << res << endl;
    }
}