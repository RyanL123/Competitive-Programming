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
        int n;
        cin >> n;
        int frq[110];
        memset(frq, 0, sizeof(frq));
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            frq[x]++;
        }
        int mexa = 0, mexb = 0;
        for (int i = 0; i <= 100; i++) {
            if (frq[i] > 0) mexa++, frq[i]--;
            else break;
        }
        for (int i = 0; i <= 100; i++) {
            if (frq[i] > 0) mexb++, frq[i]--;
            else break;
        }
        cout << mexa + mexb << '\n';
    }
}