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

const int MM = 505;
int blockedH[MM][MM], blockedV[MM][MM], ans, n;
string maze[MM];

bool checkH(int i, int j, int k){
    return blockedH[i][j] == blockedH[i][j+k];
}

bool checkV(int i, int j, int k){
    return blockedV[i][j] == blockedV[i+k][j];
}

int solve(int i, int j){
    int ret = ans;
    if (maze[i-1][j-1] == '#') return 0;
    for (int k = ans; k < n; k++){
        if (i+k <= n && j+k <= n && checkH(i, j, k) && checkV(i, j+k, k) && checkH(i+k, j, k) && checkV(i, j, k)){
            ret = k;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> maze[i-1];
        for (int j = 1; j <= n; j++){
            blockedH[i][j] = blockedH[i][j-1] + (maze[i-1][j-1] == '#');
            blockedV[i][j] = blockedV[i-1][j] + (maze[i-1][j-1] == '#');
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans << '\n';
}