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

struct Q{
    int l, r, k, id;
};
int N, M;
ll bit[200010], ans[200010];
vector<Q> q;
vii a;
bool cmp(Q x, Q y) {
    return x.k < y.k;
}

void upd(int pos, int val){
    for (int i = pos; i <= N; i += i&-i) bit[i] += val;
}

ll qry(int pos){
    ll ret = 0;
    for (int i = pos; i; i -= i&-i) ret += bit[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        int x;
        cin >> x;
        a.pb(mp(x, i));
        upd(i, x);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= M; i++){
        int l, r, k;
        cin >> l >> r >> k;
        q.push_back(Q{l, r, k, i});
    }
    sort(q.begin(), q.end(), cmp);
    for (int i = 0, j = 0; i < M; i++){
        while (j < N && a[j].first < q[i].k){
            upd(a[j].second, -2*a[j].first);
            j++;
        }
        ans[q[i].id] = qry(q[i].r) - qry(q[i].l-1);
    }
    for (int i = 1; i <= M; i++){
        cout << ans[i] << "\n";
    }
}