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
    int m, s;
    cin >> m >> s;
    if (s == 0 && m == 1) cout << "0 0\n";
    else if (s > m*9 || s == 0) cout << "-1 -1\n";
    else {
        vi mx, mn;
        int S = s;
        while (s>=9){
            mx.pb(9);
            s-=9;
        }
        if (s != 0) mx.pb(s);
        int len = 0, tot = 0;
        for (int i = 1; i <= m; i++){
            int cur = (i==1);
            while ((m-i)*9 < S-tot-cur && cur < 9) cur++;
            mn.pb(cur);
            tot += cur;
            len++;
            if (tot == S) break;
        }
        for (int i : mn) cout << i;
        for (int i = 0; i < m-len; i++) cout << '0';
        cout << ' ';
        for (int i : mx) cout << i;
        for (int i = 0; i < m-mx.size(); i++) cout << '0';
    }
}