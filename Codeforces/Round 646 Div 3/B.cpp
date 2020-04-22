#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        if (n%4!=0) cout << "NO\n";
        else {
            cout << "YES\n";
            int a[n+1];
            int cur = 2;
            for (int i = 0; i < n/2; i++){
                a[i] = cur;
                if (i%2==0) a[n-1-i] = cur+1;
                else a[n-1-i] = cur-1;
                cur += 4;
            }
            for (int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
}