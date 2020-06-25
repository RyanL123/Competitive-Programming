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
    int T;
    cin >> T;
    while (T--){
        string s;
        int m;
        cin >> s >> m;
        int b[m+1];
        queue<int> q;
        char t[m+1];
        bool done[m+1];
        int frq[26];
        memset(frq, 0, sizeof(frq));
        memset(done, false, sizeof(done));
        for (int i = 0; i < m; i++){
            cin >> b[i];
        }
        for (int i = 0; i < s.length(); i++){
            frq[s[i] - 'a']++;
        }
        int tot = 0;
        vector<vi> g;
        while (tot != m){
            vi v;
            for (int i = 0; i < m; i++){
                if (!done[i] && b[i] == 0){
                    done[i] = true;
                    tot++;
                    v.pb(i);
                }
            }
            for (int i = 0; i < m; i++){
                if (b[i] != 0){
                    for (int j : v) b[i] -= abs(i-j);
                }
            }
            g.pb(v);
        }
        int ptr = 25;
        for (vi v : g){
            while (frq[ptr] < v.size()){
                ptr--;
            }
            for (int i : v){
                t[i] = ptr + 'a';
            }
            ptr--;
        }
        for (int i = 0; i < m; i++){
            cout << t[i];
        }
        cout << '\n';
    }
}