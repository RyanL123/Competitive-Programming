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

bool dp[2][490010];
int a[710];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int m;
        cin >> m;
        a[i] = m;
        s += m;
    }
    dp[0][0] = true;
    dp[1][0] = true;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= s; j++){
            if (i%2==1){
                dp[1][j] = dp[0][j];
                if (a[i] <= j){
                    dp[1][j] |= dp[0][j-a[i]];
                }
            }
            else {
                dp[0][j] = dp[1][j];
                if (a[i] <= j){
                    dp[0][j] |= dp[1][j-a[i]];
                }
            }
        }
    }
    for (int i = s/2; i >= 0; i--){
        if (n%2==0){
            if (dp[0][i]){
                cout << s-2*i;
                return 0;
            }
        }
        else {
            if (dp[1][i]){
                cout << s-2*i;
                return 0;
            }
        }
    }
}