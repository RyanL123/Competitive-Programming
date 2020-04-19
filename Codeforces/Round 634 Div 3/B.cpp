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
    int t;
    cin >> t;
    while (t--){
        int n, a, b;
        cin >> n >> a >> b;
        char cur = 'a';
        int i = 0;
        while (i < n){
            if (cur >= 'a'+b){
                cur = 'a';
                for (int j = 0; j < b-1 && i < n; j++){
                    cout << cur;
                    cur++;
                    i++;
                }
            }
            else {
                cout << cur;
                cur++;
                i++;
            }
        }
        cout << "\n";
    }
}