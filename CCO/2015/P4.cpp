#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

string parking[2010];
int n, m;

void solve(char dir, int r, int c){
    if (dir == 'N'){
        for (int i = r-1; i >= 0; i--){
            if (parking[i][c] != '.'){
                solve(parking[i][c], i, c);
            }
        }
        parking[r][c] = '.';
        cout << "(" << r << "," << c << ")\n";
    }
    else if (dir == 'S'){
        for (int i = r+1; i < n; i++){
            if (parking[i][c] != '.'){
                solve(parking[i][c], i, c);
            }
        }
        parking[r][c] = '.';
        cout << "(" << r << "," << c << ")\n";
    }
    else if (dir == 'E'){
        for (int i = c+1; i < n; i++){
            if (parking[r][i] != '.'){
                solve(parking[r][i], r, i);
            }
        }
        parking[r][c] = '.';
        cout << "(" << r << "," << c << ")\n";
    }
    else if (dir == 'W') {
        for (int i = c-1; i >= 0; i--){
            if (parking[r][i] != '.'){
                solve(parking[r][i], r, i);
            }
        }
        parking[r][c] = '.';
        cout << "(" << r << "," << c << ")\n";
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> parking[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (parking[i][j] != '.'){
                solve(parking[i][j], i, j);
            }
        }
    }
}
