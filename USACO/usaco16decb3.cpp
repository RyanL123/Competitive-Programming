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

int frq1[26], frq2[26], ans[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        memset(frq1, 0, sizeof(frq1));
        memset(frq2, 0, sizeof(frq2));
        for (int j = 0; j < a.size(); j++) frq1[a[j]-'a']++;
        for (int j = 0; j < b.size(); j++) frq2[b[j]-'a']++;
        for (int j = 0; j < 26; j++) ans[j] += max(frq1[j], frq2[j]);
    }
    for (int j = 0; j < 26; j++) cout << ans[j] << '\n';
}