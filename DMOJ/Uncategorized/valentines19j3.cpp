#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(a, b) push_back(a, b)
#define eb(a, b) emplace_back(a, b)
#define inf INT_MAX

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll l = 0;
    ll o = 0;
    ll v = 0;
    ll e = 0;
    for (int i = s.length()-1; i >= 0; i--){
        if (s[i] == 'e'){
            e++;
        }
        else if (s[i] == 'v'){
            v += e;
        }
        else if (s[i] == 'o'){
            o += v;
        }
        else if (s[i] == 'l'){
            l += o;
        }
    }
    cout << l << endl;
}
