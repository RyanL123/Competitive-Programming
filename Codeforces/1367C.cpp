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

int find(string s, int ind){
    for (int i = ind; i < s.length(); i++){
        if (s[i] == '1') return i;
    }
    return inf;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int prev = -inf;
        int ans = 0;
        int pos = find(s, 0);
        for (int i = 0; i < n; i++){
            if (prev >= pos) pos = find(s, i);
            if (s[i] == '0'){
                if (i - prev - 1 >= k && pos - i - 1 >= k){
                    ans++;
                    prev = i;
                }
            }
            else if (s[i] == '1') prev = i;
        }
        cout << ans << '\n';
    }
}