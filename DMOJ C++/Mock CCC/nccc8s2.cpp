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

ll mod = 1e9+7;
int frq[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin >> S;
    ll ans = 1;
    for (int i = 0; i < S.size(); i++) {
        frq[S[i]-'a']++;
    }
    for (int i = 0; i <= 25; i++) {
        ans *= frq[i]+1;
        ans %= mod; 
    }
    cout << ans << '\n';
}