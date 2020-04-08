#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

bool marked[110][110];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int total = n*n;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        for (int j = 1; j <= n; j++){
            if (!marked[x][j]) total--;
            marked[x][j] = true;
        }
        for (int j = 1; j <= n; j++){
            if (!marked[j][y]) total--;
            marked[j][y] = true;
        }
        for (int j = 1; j <= n; j++){
            if (x + j <= n && y + j <= n){
                if (!marked[x+j][y+j]) total--;
                marked[x+j][y+j] = true;
            }
            if (x + j <= n && y - j >= 1){
                if (!marked[x+j][y-j]) total--;
                marked[x+j][y-j] = true;
            }
            if (x - j >= 1 && y + j <= n){
                if (!marked[x-j][y+j]) total--;
                marked[x-j][y+j] = true;
            }
            if (x - j >= 1 && y - j >= 1){
                if (!marked[x-j][y-j]) total--;
                marked[x-j][y-j] = true;
            }
        }
    }
    cout << total;
}
