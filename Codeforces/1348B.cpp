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
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        set<int> s;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            s.insert(x);
        }
        if (s.size() > k) cout << "-1\n";
        else {
            int cur = 1;
            while (s.size() < k && cur <= n){
                s.insert(cur);
                cur++;
            }
            cout << k*n << '\n';
            for (int i = 0; i < n; i++){
                for (int j : s){
                    cout << j << ' ';
                }
            }
            cout << '\n';
        }
    }
}
