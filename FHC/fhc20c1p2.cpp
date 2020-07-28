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

void solve(int id) {
    char ans = 'Y';
    string s;
    int n;
    cin >> n >> s;
    while (s.size() != 1) {
        bool possible = false;
        int A = 0, B = 0;
        string ret = "";
        for (int i = 0; i < s.size(); i++) {
            s[i]=='A'?A++:B++;
            if (i >= 3) s[i-3]=='A'?A--:B--;
            if ((A == 2 || B == 2) && i >= 2) {
                ret += s.substr(0, i-2);
                ret += (A==2?"A":"B");
                ret += s.substr(i+1, s.size());
                possible = true;
                break;
            }
        }
        if (!possible && s.size() != 1) {
            ans = 'N';
            break;
        }
        else s = ret;
    }
    cout << "Case #" << id << ": " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    freopen("output.txt", "w", stdout);
    for (int i = 1; i <= t; i++) solve(i);
}