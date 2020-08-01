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

const int MM = 1e5+5;
int bit[MM];

void upd(int pos) {
    for (int i = pos; i < MM; i += (i&-i)) bit[i]++;
}

int qry(int pos) {
    int ret = 0;
    for (int i = pos; i; i -= (i&-i)) ret += bit[i];
    return ret;
}

struct rk{
    int pt, id, rel;
};

bool cmp(rk x, rk y) {
    return x.pt > y.pt;
}

bool cmp2(rk x, rk y){
    return x.id < y.id;
}

int main() {
    int t;
    scanf("%d", &t);
    vector<rk> v;
    for (int i = 1, x; i <= t; i++) {
        scanf("%d", &x);
        v.pb({x, i, 0});
    }
    sort(all(v), cmp);
    int cur = 1;
    for (int i = 0; i < t; i++) {
        if (i > 0 && v[i].pt == v[i-1].pt) v[i].rel = v[i-1].rel;
        else v[i].rel = cur, cur++;
    }
    sort(all(v), cmp2);
    ld tot = 0;
    for (int i = 0; i < t; i++) {
        if (v[i].rel != 1) tot += qry(v[i].rel-1)+1;
        else tot++;
        upd(v[i].rel);
    }
    tot /= t;
    tot *= 100;
    tot = rint(tot);
    tot /= 100;
    printf("%.2Lf\n", tot);
}