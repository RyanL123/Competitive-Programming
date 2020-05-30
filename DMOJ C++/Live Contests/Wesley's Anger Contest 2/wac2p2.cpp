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

struct interval{
    ll s, e, p;
};

bool cmp(interval a, interval b){
    return a.p < b.p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<interval> v;
    ll prevDay = n, prevPrice = 1000000;
    for (int i = 0; i < q; i++){
        ll d, p;
        cin >> d >> p;
        v.pb({prevDay, d, prevPrice});
        prevDay = d, prevPrice = p;
    }
    v.pb({prevDay, 1, prevPrice});
    sort(all(v), cmp);
    ll tot = 0, req = m;
    set<ll> used;
    for (interval i : v){
        if (req == 0) break;
        ll diff = i.s-i.e+1;
        if (used.find(i.s) != used.end()) diff--;
        if (i.e != i.s && used.find(i.e) != used.end()) diff--;
        used.insert(i.s);
        used.insert(i.e);
        tot += min(diff, req)*i.p;
        req -= min(diff, req);
    }
    cout << tot << "\n";
}
