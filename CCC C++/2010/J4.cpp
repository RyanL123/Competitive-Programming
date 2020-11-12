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

int a[25], d[25];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while (cin >> N) {
        if (N == 0) break;
        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 1; i < N; i++) d[i] = a[i]-a[i-1];
        int ans = N-1;
        for (int i = 1; i < N; i++) {
            bool flag = true;
            for (int j = 1; j < N; j++) {
                if (i+j < N) {
                    flag &= (d[j] == d[j+i]);
                }
            }
            if (flag) ans = min(ans, i);
        }
        cout << ans << '\n';
    }
}