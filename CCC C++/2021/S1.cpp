#include <bits/stdc++.h>

using namespace std;

const int MM = 1e4+5;
int h[MM], w[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    double ans = 0;
    cin >> N;
    for (int i = 0; i <= N; i++) cin >> h[i];
    for (int i = 0; i < N; i++) cin >> w[i];
    for (int i = 0; i < N; i++) {
        ans += (double)(w[i]*abs(h[i]-h[i+1]))/2;
        ans += w[i]*min(h[i], h[i+1]);
    }
    cout << fixed << ans << '\n';
}