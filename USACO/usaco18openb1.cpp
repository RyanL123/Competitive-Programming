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

string t[3];
int a, b;

bool one(char c) {
    bool ret = false;
    for (int i = 0; i < 3; i++) {
        ret |= ((t[i][0] == c) && (t[i][1] == c) && (t[i][2] == c));
    }
    for (int i = 0; i < 3; i++) {
        ret |= ((t[0][i] == c) && (t[1][i] == c) && (t[2][i] == c));
    }
    ret |= (t[0][0] == t[1][1] && t[1][1] == t[2][2] && t[2][2] == c);
    ret |= (t[0][2] == t[1][1] && t[1][1] == t[2][0] && t[2][0] == c);
    return ret;
}

bool two(char c, char d) {
    bool ret = false;
    for (int i = 0; i < 3; i++) {
        bool cur = ((t[i][0] == c || t[i][0] == d) && (t[i][1] == c || t[i][1] == d) && (t[i][2] == c || t[i][2] == d));
        cur &= !(t[i][0] == t[i][1] && t[i][1] == t[i][2]);
        ret |= cur;
    }
    for (int i = 0; i < 3; i++) {
        bool cur = ((t[0][i] == c || t[0][i] == d) && (t[1][i] == c || t[1][i] == d) && (t[2][i] == c || t[2][i] == d));
        cur &= !(t[0][i] == t[1][i] && t[1][i] == t[2][i]);
        ret |= cur;
    }
    bool cur = ((t[0][0] == c || t[0][0] == d) && (t[1][1] == c || t[1][1] == d) && (t[2][2] == c || t[2][2] == d));
    cur &= !(t[0][0] == t[1][1] && t[1][1] == t[2][2]);
    ret |= cur;
    cur = ((t[0][2] == c || t[0][2] == d) && (t[1][1] == c || t[1][1] == d) && (t[2][0] == c || t[2][0] == d));
    cur &= !(t[0][2] == t[1][1] && t[1][1] == t[2][0]);
    ret |= cur;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    for (int i = 0; i < 3; i++) cin >> t[i];
    for (char i = 'A'; i <= 'Z'; i++) {
        a += one(i);
        for (char j = i+1; j <= 'Z'; j++) b += two(i, j);
    }
    cout << a << "\n" << b << "\n";
}