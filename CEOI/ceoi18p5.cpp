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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<set<int>> res;
    vi v;
    for (int i = 1; i*i <= n; i++){
        if (n%i==0){
            v.pb(n/i);
            if (n/i != i) v.pb(i);
        }
    }
    srt(v);
    res.resize(v.size());
    res[0].insert(0);
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < i; j++){
            if (v[i]%v[j] == 0){
                for (int k : res[j]) {
                    res[i].insert(v[i]/v[j] + k - 1);
                }
            }
        }
    }
    cout << res.back().size() << '\n';
    for (auto i : res.back()){
        cout << i << ' ';
    }
}