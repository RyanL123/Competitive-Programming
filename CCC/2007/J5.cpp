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

ll dp[7010];

bool hotel[7010];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    if (a > b){
        cout << 0 << endl;
        return 0;
    }
    hotel[0] = true;
    hotel[990] = true;
    hotel[1010] = true;
    hotel[1970] = true;
    hotel[2030] = true;
    hotel[2940] = true;
    hotel[3060] = true;
    hotel[3930] = true;
    hotel[4060] = true;
    hotel[4970] = true;
    hotel[5030] = true;
    hotel[5990] = true;
    hotel[6010] = true;
    hotel[7000] = true;
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        hotel[m] = true;
    }
    int first = -1;
    for (int i = 0; i <= b; i++){
        if (hotel[i]){
            dp[i] = 1;
            first = i;
            break;
        }
    }
    if (first == -1){
        cout << 0 << endl;
        return 0;
    }
    for (int i = first; i <= 7000; i++){
        ll ans = 0;
        if (hotel[i]){
            for (int j = max(0,i-b); j <= max(0,i-a); j++){
                if (hotel[j]) ans += dp[j];
            }
            dp[i] = ans;
        }
    }
    cout << dp[7000] << endl;
}