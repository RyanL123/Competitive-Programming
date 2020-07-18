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
        int R = 0, P = 0, S = 0;
        for (int i = 0; i < s.size(); i++) {
            R += (s[i] == 'R');
            P += (s[i] == 'P');
            S += (s[i] == 'S');
        }
        int mx = max(R, max(P, S));
        if (mx == R) {
            cout << string(s.size(), 'P') << '\n';
        } 
        else if (mx == P) {
            cout << string(s.size(), 'S') << '\n';
        } 
        else {
            cout << string(s.size(), 'R') << '\n';
        }
    }
}