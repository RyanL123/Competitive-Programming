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

const int MM = 2e5+5, MN = 25;
int A[MM][MN];
vii v[MN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M, N, K, ans = 0;
    cin >> M >> N >> K;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            v[j].eb(A[i][j], i);
        }
    }
    for (int i = 1; i < N; i++) {
        srt(v[i]);
        for (int l = 0, r = 0; r < M; r++) {
            while (l <= r && v[i][r].first > v[i][l].first+K) l++;
            if (v[i][r].first == v[i][l].first+K) {
                int r1 = v[i][l].second, r2 = v[i][r].second;
                ans += (A[r2][i+1] - A[r1][i+1] == K);
            }
        }
    }
    cout << ans << '\n';
}