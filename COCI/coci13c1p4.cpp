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
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vii j;
    for (int i = 0; i < n; i++){
        int m, v;
        cin >> m >> v;
        j.eb(v, m);
    }
    srt(j);
    multiset<int> b;
    for (int i = 0; i < k; i++){
        int c;
        cin >> c;
        b.insert(c);
    }
    ll tot = 0;
    for (int i = n-1; i >= 0; i--){
        int m = j[i].second, v = j[i].first;
        auto pos = b.lower_bound(m);
        if (pos != b.end()){
            tot += v;
            b.erase(pos);
        }
    }
    cout << tot << "\n";
}