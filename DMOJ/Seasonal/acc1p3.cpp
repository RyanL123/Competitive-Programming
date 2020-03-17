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

ull a[100010];
ull b[100010];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull t, n, m = 998244353;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cin >> b[i];
    }
    ull lo = 0, hi = 10;
    while (lo < hi){
        ull mid = (lo+hi)/2;
        ull h = 0;
        ull count = 0;
        for (int i = 0; i < n; i++){
            if (a[i] >= mid){
                ull terms = floor((a[i]-mid)/b[i])+1;
                ull lastTerm = a[i]-b[i]*(terms-1);
                ull sum = (terms*(a[i] + lastTerm))/2;
                h += sum%m;
                count += terms;
            }
        }
        if (count == t || lo == hi){
            cout << h%m << "\n";
            return 0;
        }
        else if (count > t) lo = mid+1;
        else if (count < t) hi = mid;
    }
}