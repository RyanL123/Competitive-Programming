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
        int n, m;
        cin >> n >> m;
        bool row[n], col[m];
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int x;
                cin >> x;
                row[i] |= (x == 1);
                col[j] |= (x == 1);
            }
        }
        int cnt = 0;
        while (true){
            int r = inf, c = inf;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (!row[i] && !col[j]){
                        r = i, c = j;
                        row[i] = true, col[j] = true;
                        goto done;
                    }
                }
            }
            done:
            if (r == inf || c == inf) break;
            cnt++;
        }
        cout << (cnt%2==0 ? "Vivek" : "Ashish") << '\n';
    }
}