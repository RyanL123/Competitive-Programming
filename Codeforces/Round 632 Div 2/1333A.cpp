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
        int n, m;
        cin >> n >> m;
        for (int i = n; i >= 2; i--){
            for (int j = 0; j < m; j++){
                cout << "B";
            }
            cout << "\n";
        }
        cout << "B";
        for (int i = 0; i < m-1; i++){
            cout << "W";
        }
        cout << "\n";
    }
}