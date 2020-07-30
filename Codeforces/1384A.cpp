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
        string s = string(55, 'a');
        cout << s << '\n';
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            string cur = s;
            for (int i = a; i < s.size(); i++) {
                if (s[i] == 'z') cur[i] = 'a';
                else cur[i] = s[i] + 1;
            }
            cout << cur << '\n';
            s = cur;
        }
    }
}