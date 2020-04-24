/*
ID: ryan.li2
TASK: beads
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

string s;

int calc(int n){
    string f = s.substr(n, s.length()) + s.substr(0, n);
    int l = 0, r = s.length()-1, cnt = 0;
    char cur;
    for (int i = 0; i < s.length(); i++){
        if (f[i] != 'w'){
            cur = f[i];
            cnt = i+1;
            l = i+1;
            break;
        }
    }
    while (l <= r){
        if (f[l] == 'w' || f[l] == cur) cnt++;
        else break;
        l++;
    }
    if (cur == f[r]) return cnt;
    for (int i = s.length()-1; i >= 0; i--){
        if (f[i] != 'w'){
            cur = f[i];
            cnt += s.length()-i;
            r = i-1;
            break;
        }
    }
    while (r >= 0){
        if (f[r] == 'w' || f[r] == cur) cnt++;
        else break;
        r--;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("beads.in", "r", stdin);
    int n, ans = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        ans = max(ans, calc(i));
    }
    freopen("beads.out", "w", stdout);
    cout << min(ans, n) << "\n";
}