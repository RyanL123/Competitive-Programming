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

ll ans[100005];

bool cmp(pii x, pii y){
    return x.first < y.first || (x.first == y.first && x.second > y.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r, y;
    cin >> n >> l >> r >> y;
    vector<pair<ld, int>>vec;
    for (int i = 0; i < n; i++){
        int x, v = 0, h = 0;
        cin >> x >> v >> h;
        ld close = (ld)(y*h)/v+x;
        ld open = (ld)(y*-h)/v+x;
        if (y*h % v == 0){
            open++, close--;
        }
        else {
            close = floor(close);
            open = ceil(open);
        }
        vec.eb(max(l, (int)open), 1);
        vec.eb(min(r, (int)close), -1);
    }
    sort(all(vec), cmp);
    int prev = l, dir = 1;
    int cur = 0;
    for (int i = 0; i < vec.size(); i++){
        int diff = abs(vec[i].first - prev);
        if (dir == 1 && vec[i].second == -1) diff++;
        if (dir == -1 && vec[i].second == 1) diff--;
        ans[cur] += diff;
        prev = vec[i].first;
        dir = vec[i].second;
        cur += vec[i].second;
    }
    ans[cur] += r - prev;
    cout << ans[0] << '\n';
    for (int i = 1; i <= n; i++){
        ans[i] += ans[i-1];
        cout << ans[i] << '\n';
    }
}