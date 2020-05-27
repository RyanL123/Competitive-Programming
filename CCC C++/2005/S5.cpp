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
    int t;
    double tot = 0;
    cin >> t;
    vi v;
    for (int i = 0; i < t; i++){
        int x;
        cin >> x;
        auto it = upper_bound(v.begin(), v.end(), x);
        int dis = distance(v.begin(), it);
        tot += v.size()-dis+1;
        v.insert(it, x);
    }
    cout << fixed << setprecision(2) << tot/t;
}