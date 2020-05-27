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

void solve(string s){
    s += '0';
    s = '0' + s;
    int n = s.length();
    for (int i = 0; i < n-1; i++){
        int diff = s[i+1] - s[i];
        if (diff < 0){
            for (int j = 0; j < abs(diff); j++){
                cout << ')';
            }
        }
        else {
            for (int j = 0; j < diff; j++){
                cout << '(';
            }
        }
        if (i != n-2) cout << s[i+1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        string s;
        cin >> s;
         cout << "Case #" << i << ": ";
        solve(s);
        cout << '\n';
    }
}