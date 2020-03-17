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
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        vi col;
        int n;
        cin >> n;
        int highest = 0;
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            if (a > highest) highest = a;
            col.pb(a);
        }
        bool even = (highest-col[0])%2==0;
        bool flag = false;
        for (int j = 1; j < n; j++){
            if (even && (highest-col[j])%2!=0){
                flag = true;
            }
            else if (!even && (highest-col[j])%2==0){
                flag = true;
            }
        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }
}
