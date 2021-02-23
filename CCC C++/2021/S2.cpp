#include <bits/stdc++.h>

using namespace std;

const int MM = 5e6+5;
bool R[MM], C[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, K, curR = 0, curC = 0, ans = 0;
    vector<pair<int, int>> v;
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'R') v.emplace_back(1, x);
        else v.emplace_back(2, x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < K; i++) {
        int x = v[i].second;
        if (v[i].first == 1) R[x] = !R[x];
        else C[x] = !C[x];
    }
    for (int i = 1; i <= N; i++) {
        curR += R[i];
        if (R[i]) ans += M;
    }
    for (int i = 1; i <= M; i++) {
        curC += C[i];
        if (C[i]) ans += N;
    }
    cout << ans-2*curR*curC << '\n';

}