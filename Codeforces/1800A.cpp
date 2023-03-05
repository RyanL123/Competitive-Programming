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
        string s;
        cin >> n >> s;
        vector<char> v = {'m', 'e', 'o', 'w'};
        vi cnt(4);
        int j = 0;
        for (int i = 0; i < 4; i++) {
            while (j < n && tolower(s[j]) == v[i]) {
                cnt[i]++;
                j++;
            }
        }
        bool can = true;
        for (int i = 0; i < 4; i++) can &= cnt[i] > 0;
        cout << (can && j == n ? "yes" : "no") << endl;
    }
}