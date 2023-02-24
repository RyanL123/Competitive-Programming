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
    while (t--) {
        int W, a, b;
        cin >> W;
        int gap = 0, can = 1;
        for (int i = 0; i < W; i++) {
            cin >> a >> b;
            if (gap == 0) gap = a-b;
            if (gap != a-b) can = 0;
        }
        if (W != 0) cout << (can ? "yes" : "no") << endl;
        if (t != 0) cout << endl;
    }
    
}