/*
ID: ryan.li2
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ride.in", "r", stdin);
    string c, s;
    cin >> c >> s;
    freopen("ride.out", "w", stdout);
    int C = 1, S = 1;
    for (int i = 0; i < c.length(); i++){
        C *= c[i] - 'A' + 1;
    }
    for (int i = 0; i < s.length(); i++){
        S *= s[i] - 'A' + 1;
    }
    if (C%47 == S%47) cout << "GO\n";
    else cout << "STAY\n";
}