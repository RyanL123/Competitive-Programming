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

string solve(string s) {
    string t = "abacaba";
    for (int i = 0; i < t.size(); i++) {
        if (s[i] == t[i] || s[i] == '?') continue;
        else return s;
    }
    return t;
}

void replace(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') s[i] = 'z';
    }
}

int check(string s) {
    string t = "abacaba";
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        ret += s.substr(i, 7) == t;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> n >> s;
        bool flag = false;
        for (int i = 0; i <= s.size()-7; i++) {
            string tmp = s;
            tmp = tmp.substr(0, i) + solve(s.substr(i, 7)) + tmp.substr(i+7, s.size());
            replace(tmp);
            if (check(tmp) == 1) {
                flag = true;
                cout << "YES\n";
                cout << tmp << '\n';
                break;
            }
        }
        if (!flag) cout << "NO\n";
    }
}