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

bool mark[2005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string s;
    vector<string> c;
    cin >> N >> s;
    for (int i = 0; i <= 2000; i++) {
        c.pb(string(N, '.'));
    }
    int r = 1000;
    for (int i = 0; i < N; i++) {
        if (s[i] == '^') {
            c[r][i] = '/';
            mark[r] = true;
            r--;
        }
        else if (s[i] == 'v') {
            r++;
            c[r][i] = '\\';
            mark[r] = true;
        }
        else {
            mark[r] = true;
            c[r][i] = '_';
        }
    }
    for (int i = 0; i <= 2000; i++) {
        if (mark[i]) cout << c[i] << '\n';
    }
}