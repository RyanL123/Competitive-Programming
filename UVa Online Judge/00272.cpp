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
    string s;
    int cnt = 0;
    while (getline(cin, s, '\n')) {
        string out;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '\"') {
                if (cnt % 2 == 0) {
                    out.pb('`');
                    out.pb('`');
                }
                else {
                    out.pb('\'');
                    out.pb('\'');
                }
                cnt++;
            }
            else out.pb(s[i]);
        }
        cout << out << endl;
    }
}