#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t, s;
    cin >> t >> s;
    bool flag = false;
    for (int i = 0; i < s.length(); i++){
        if (flag) break;
        for (int j = 0; j <= t.length()-s.length(); j++){
            if (t.substr(j, s.length()) == s){
                flag = true;
                break;
            }
        }
        s = s.substr(1, s.length()-1) + s[0];
    }
    cout << (flag?"yes":"no") << endl;
}
