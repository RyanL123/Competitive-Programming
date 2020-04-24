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
        ll a[n+1];
        ll sum = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ptr = 0;
        bool pos = a[0] > 0;
        ll cur = -1000000005;
        while (ptr < n){
            if (pos && a[ptr] > 0){
                cur = max(a[ptr], cur);
            }
            else if (!pos && a[ptr] < 0){
                cur = max(a[ptr], cur);
            }
            else if ((pos && a[ptr] < 0) || (!pos && a[ptr] > 0)){
                sum += cur;
                cur = -inf;
                pos = !pos;
                cur = max(a[ptr], cur);
            }
            ptr++;
        }
        sum += cur;
        cout << sum << "\n";
    }
}