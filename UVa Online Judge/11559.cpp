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
    int N, B, H, W;
    while (cin >> N >> B >> H >> W) {
        int mn = inf;
        int p, a;
        for (int i = 0; i < H; i++) {
            cin >> p;
            for (int j = 0; j < W; j++) {
                cin >> a;
                if (a >= N) mn = min(mn, p*N);
            }
        }
        if (mn > B) cout << "stay home" << endl;
        else cout << mn << endl;
    }
}