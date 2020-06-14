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
    int n, ans = 0;
    map<string, int> m;
    vector<string> v;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        v.pb(s);
        set<string> st;
        for (int j = 0; j < s.length(); j++){
            for (int k = 1; k <= s.length()-j; k++){
                string substr = s.substr(j, k);
                st.insert(substr);
            }
        }
        for (auto x : st){
            m[x]++;
        }
    }
    for (int i = 0; i < n; i++){
        ans += m[v[i]]-1;
    }
    cout << ans << '\n';
}
