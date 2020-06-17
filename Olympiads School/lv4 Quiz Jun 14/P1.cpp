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
    int N, ans = inf, l = 0, r = 0;
    cin >> N;
    string s;
    cin >> s;
    for (int i = 0; i < N; i++){
        if (s[i] == 'L') l++;
        else r++;
    }
    int L = 0, R = 0;
    for (int i = 0; i < N; i++){
        ans = min(ans, L + (r - R - (s[i] == 'R')));
        if (s[i] == 'L'){
            L++;
        }
        else {
            R++;
        }
    }
    cout << ans << '\n';
}