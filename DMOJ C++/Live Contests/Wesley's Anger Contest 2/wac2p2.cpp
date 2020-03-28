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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, q, total = 0;
    vector<tuple<ll, ll, ll>> costumes;
    cin >> n >> m >> q;
    ll lastDay = n;
    for (int i = 0; i < q; i++){
        ll d, p;
        cin >> d >> p;
        costumes.pb(make_tuple(p, lastDay, d));
        lastDay = d;
    }
    sort(costumes.begin(), costumes.end());
    vector<ll> used;
    cout << total << "\n";
}
