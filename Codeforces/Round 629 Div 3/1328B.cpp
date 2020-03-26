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
        int n, k;
        cin >> n >> k;
        int prev = 0;
        int c = 0;
        int term = 0;
        while (c + prev < k){
            c += prev;
            prev++;
            term++;
        }
        if (c == k){
            for (int i = 0; i < n-term-1; i++){
                cout << "a";
            }
            cout << "b";
            for (int i = n-term+1; i < n; i++){
                cout << "a";
            }
            cout << "b\n";
        }
        else {
            int pos1 = (n - 1) - term;
            int pos2 = n - (k - c);
            for (int i = 0; i < pos1; i++){
                cout << "a";
            }
            cout << "b";
            for (int i = pos1+1; i < pos2; i++){
                cout << "a";
            }
            cout << "b";
            for (int i = pos2+1; i < n; i++){
                cout << "a";
            }
            cout << "\n";
        }
    }
}