#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(a, b) push_back(a, b)
#define eb(a, b) emplace_back(a, b)
#define inf INT_MAX

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int a, b, n;
        cin >> a >> b >> n;
        bool flag = false;
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                if (a*i + b*j == n){
                    flag = true;
                }
            }
        }
        if (flag){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
