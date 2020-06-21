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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int cnt = 0;
        string grid[n];
        for (int i = 0; i < n; i++){
            cin >> grid[i];
            for (int j = 0; j < m; j++){
                cnt += (grid[i][j] == '.');
            }
        }
        if (2*x <= y){
            cout << cnt*x << '\n';
        }
        else {
            int cost = 0;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < m; j++){
                    if (grid[i][j]=='.'&&j+1<m&&grid[i][j+1]=='.'){
                        cost+=y;
                        j++;
                    }
                    else if (grid[i][j]=='.') cost+=x;
                }
            }
            cout << cost << "\n";
        }
    }
}