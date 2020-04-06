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

bool valid(string s){
    int n = s.length();
    if (n == 1 && s == "A") return true;
    else if (n == 1) return false;
    bool ans = false;
    for (int i = 0; i < n; i++){
        if (s[i] == 'N'){
            ans |= valid(s.substr(0, i)) && valid(s.substr(i+1, n));
        }
    }
    if (s[0] == 'B' && s[n-1] == 'S'){
        ans |= valid(s.substr(1, n-2));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin >> s){
        if (s == "X") break;
        else if (valid(s)) cout << "YES\n";
        else cout << "NO\n";
    }
}
