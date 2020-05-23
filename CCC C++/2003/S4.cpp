#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int lcp(string a, string b){
    int ret = 0;
    for (int i = 0; i < min(a.length(), b.length()); i++){
        if (a[i] == b[i]) ret++;
        else break;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while (N--){
        string s;
        cin >> s;
        int n = s.length();
        vector<string> suffix;
        for (int i = 0; i < n; i++){
            suffix.pb(s.substr(i, n));
        }
        srt(suffix);
        int ans = 1+suffix[0].length();
        for (int i = 1; i < suffix.size(); i++){
            ans += suffix[i].length() - lcp(suffix[i], suffix[i-1]);
        }
        cout << ans << '\n';
    }
}