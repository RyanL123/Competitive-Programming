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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        map<string, vii> M;
        for (int i = 0; i < n; i++){
            int m;
            cin >> m;
            for (int j = 0; j < m; j++){
                string s;
                int p, q;
                cin >> s >> p >> q;
                M[s].pb({p, q});
                srt(M[s]);
            }
        }
        int k, tot = 0;
        cin >> k;
        for (int i = 0; i < k; i++){
            string s;
            int d, cur = 0;
            cin >> s >> d;
            while (d != 0){
                if (M[s][cur].second == 0) cur++;
                tot += M[s][cur].first;
                M[s][cur].second--;
                d--;
            }
        }
        cout << tot << '\n';
    }
}