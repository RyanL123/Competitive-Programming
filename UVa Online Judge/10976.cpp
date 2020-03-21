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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double k;
    while (cin >> k && k != EOF){
        vii ans;
        for (long double i = k+1; i <= 2*k; i++){
            long double y = 1/(1/k - 1/i);
            if (abs(y - round(y)) <= 1e-5){
                ans.pb(mp(i, round(y)));
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (pii i : ans){
            cout << "1/" << k << " = 1/" << i.second << " + " << "1/" << i.first << "\n";
        }
    }
}