#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int I = -1, J = -1, K = -1;
        for (int j = 0; j < n; j++){
            J = j;
            for (int i = 0; i < n; i++){
                if (i < j && a[i] < a[j]){
                    I = i;
                }
                if (i > j && a[i] < a[j]){
                    K = i;
                }
            }
            if (I != -1 && J != -1 && K != -1) {
                cout << "YES\n";
                cout << I+1 << " " << J+1 << " " << K+1 << '\n';
                break;
            }
            else I = J = K = -1;
        }
        if (I == -1 || J == -1 || K == -1) cout << "NO\n";
    }
}