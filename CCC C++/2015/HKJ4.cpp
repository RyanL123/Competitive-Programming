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

struct v{
    int l, r;
};

bool cmp(v a, v b){
    if (a.l != b.l) return a.l < b.l;
    return a.r < b.r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L, N, ans;
    cin >> L >> N;
    vector<v> vec;
    for (int i = 0; i < N; i++){
        int s, t;
        cin >> s >> t;
        vec.push_back({s,t});
    }
    sort(vec.begin(), vec.end(), cmp);
    v prev = vec[0];
    ans = max(prev.l, L-vec[N-1].r);
    for (int i = 1; i < N; i++){
        int l = vec[i].l, r = vec[i].r;
        if (l > prev.r){
            ans = max(ans, l - prev.r);
            prev = vec[i];
        }
        else prev = {prev.l, max(prev.r, r)};
    }
    cout << ans << "\n";
}
