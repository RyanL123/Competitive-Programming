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
vi a[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    a[1].pb(1);
    a[2].pb(2);
    for (int i = 3; i < MM; i++){
        set<int> s;
        for (int j = 2; j <= ceil(sqrt(i)); j++){
            if (i%j==0 && i!=j) {
                s.insert(j), s.insert(i/j);
            }
        }
        a[s.size()+2].pb(i);
    }
    while (t--){
        int K, A, B;
        cin >> K >> A >> B;
        auto hi = upper_bound(a[K].begin(), a[K].end(), B);
        auto lo = lower_bound(a[K].begin(), a[K].end(), A);
        cout << hi - lo << '\n';
    }
}