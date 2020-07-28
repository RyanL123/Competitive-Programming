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

char board[30][30];
int n, q;
bool solve(string s, int r, int c, char prev){
    if (s.size() == 1 && s[0] == board[r][c]) return true;
    bool ret = false;
    if (s[0] == board[r][c]) {
        if (r > 0 && prev != 'u') ret |= solve(s.substr(1, s.size()), r-1, c, 'd');
        if (r < n-1 && prev != 'd') ret |= solve(s.substr(1, s.size()), r+1, c, 'u');
        if (c > 0 && prev != 'r') ret |= solve(s.substr(1, s.size()), r, c-1, 'l');
        if (c < n-1 && prev != 'l') ret |= solve(s.substr(1, s.size()), r, c+1, 'r');
        if (r < n-1 && c < n-1 && prev != 'w') ret |= solve(s.substr(1, s.size()), r+1, c+1, 'z');
        if (r > 0 && c > 0 && prev != 'z') ret |= solve(s.substr(1, s.size()), r-1, c-1, 'w');
        if (r > 0 && c < n-1 && prev != 'y') ret |= solve(s.substr(1, s.size()), r-1, c+1, 'x');
        if (r < n-1 && c > 0 && prev != 'x') ret |= solve(s.substr(1, s.size()), r+1, c-1, 'y');
    }
    else return false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    for (int qq = 0; qq < q; qq++) {
        string s;
        cin >> s;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                flag |= solve(s, i, j, 'a');
                if (flag) break;
            }
        }
        cout << (flag?"good puzzle!\n":"bad puzzle!\n");
    }
}