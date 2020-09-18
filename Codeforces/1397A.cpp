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
        int n;
        cin >> n;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                cnt[s[j]-'a']++;
            }
        }
        bool ans = true;
        for (int i = 0; i < 26; i++) {
            ans &= (cnt[i]%n==0);
        }
        cout << (ans?"YES":"NO") << "\n";
    }
}