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

unordered_map<string, unordered_set<string>> same, diff;

// whether a and b in the same group violates any constraints
int check(string &a, string &b) {
    return diff[a].count(b) != 0 || diff[b].count(a) != 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, g;
    cin >> x;
    for (int i = 0; i < x; i++) {
        string a, b;
        cin >> a >> b;
        same[a].insert(b);
    }
    cin >> y;
    for (int i = 0; i < y; i++) {
        string a, b;
        cin >> a >> b;
        diff[a].insert(b);
    }
    int cnt = 0;
    cin >> g;
    for (int i = 0; i < g; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        cnt += check(a, b);
        cnt += check(a, c);
        cnt += check(b, c);
        cnt += same[a].size() - same[a].count(b) - same[a].count(c);
        cnt += same[b].size() - same[b].count(a) - same[b].count(c);
        cnt += same[c].size() - same[c].count(a) - same[c].count(b);
    }
    cout << cnt;
}