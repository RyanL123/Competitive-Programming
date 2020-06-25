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
        int a[n+1];
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a+1, a+n+1);
        if (n%2==0){
            for (int i = n/2; i >= 1; i--){
                cout << a[i] << " " << a[n-i+1] << " ";
            }
            cout << "\n";
        }
        else {
            cout << a[(n+1)/2] << " ";
            for (int i = n/2; i >= 1; i--){
                cout << a[i] << " " << a[n-i+1] << " ";
            }
            cout << "\n";
        }
    }
}
