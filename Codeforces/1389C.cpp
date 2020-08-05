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
        string s;
        cin >> s;
        int ans = inf, cnt[10], n = s.size();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) cnt[s[i]-'0']++;
        for (int i = 0; i < 10; i++) ans = min(ans, n-cnt[i]);
        for (char a = '0'; a <= '9'; a++) {
            for (char b = '0'; b <= '9'; b++) {
                char pre = b, cur = a;
                int del = 0, len = 0;
                for (int i = 0; i < n; i++) {
                    if (s[i] != cur) del++;
                    else len++, swap(pre, cur);
                }
                if (len%2) del++;
                ans = min(ans, del);
            }
        }
        cout << ans << '\n';
    }
}