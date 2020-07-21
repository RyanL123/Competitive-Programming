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
    int l;
    cin >> l;
    while (l--) {
        int n;
        cin >> n;
        int tot = n*10, mx = 1;
        vector<string> v;
        map<string, int> dep;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.pb(s);
        }
        dep[v.back()] = 1;
        if (v.size() > 1) dep[v.front()] = 2, mx = 2;
        for (int i = 1; i < n-1; i++) {
            if (dep[v[i]] == 0) dep[v[i]] = dep[v[i-1]]+1;
            mx = max(mx, dep[v[i]]); 
        }
        cout << tot-2*(mx-1)*10 << "\n";
    }
}