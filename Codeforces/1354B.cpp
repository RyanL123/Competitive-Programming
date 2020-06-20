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
    while (t--){
        string s;
        cin >> s;
        int n = s.length();
        int frq[3], ans = inf;
        memset(frq, 0, sizeof(frq));
        for (int l = 0, r = 0; r < n; r++){
            frq[s[r]-'1']++;
            while (frq[s[l]-'1']-1 >= 1){
                frq[s[l]-'1']--;
                l++;
            }
            if (frq[0] >= 1 && frq[1] >= 1 && frq[2] >= 1){
                ans = min(ans, r-l+1);
            }
        }
        cout << (ans==inf?0:ans) << '\n';
    }
}