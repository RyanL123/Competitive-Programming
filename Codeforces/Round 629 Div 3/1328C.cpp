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
        int n;
        cin >> n;
        string x;
        cin >> x;
        cout << '1';
        int pos = inf;
        for (int i = 1; i < n; i++){
            if (pos == inf){
                if (x[i] == '2') cout << '1';
                else if (x[i] == '0') cout << '0';
                else {
                    pos = i;
                    cout << '1';
                }
            }
            else {
                cout << '0';
            }
        }
        cout << '\n';
        cout << '1';
        for (int i = 1; i < n; i++){
            if (i < pos){
                if (x[i] == '2') cout << '1';
                else if (x[i] == '0') cout << '0';
            }
            else if (i == pos){
                cout << '0';
            }
            else {
                if (x[i] == '2') cout << '2';
                else if (x[i] == '1') cout << '1';
                else cout << '0';
            }
        }
        cout << '\n';
    }
}