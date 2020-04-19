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

int J[1000005], L[1000005], dp[2][1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a;
    for (int i = 0; i < a; i++) cin >> J[i];
    cin >> b;
    for (int i = 0; i < b; i++) cin >> L[i];
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            if (i % 2 == 1){
                dp[0][j] = max(dp[1][j], dp[0][j-1]);
                if (J[i-1] == L[j-1]) dp[0][j] = max(dp[0][j], dp[1][j-1]+1);
            }
            else {
                dp[1][j] = max(dp[0][j], dp[1][j-1]);
                if (J[i-1] == L[j-1]) dp[1][j] = max(dp[1][j], dp[0][j-1]+1);
            }
        }
    }
    if (a % 2 == 0){
        cout << dp[1][b];
    }
    else {
        cout << dp[0][b];
    }
}
