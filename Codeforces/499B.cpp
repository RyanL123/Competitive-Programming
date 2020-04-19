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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    map<string, string> dict;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        dict[a] = b;
    }
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (dict[s].length() < s.length()) cout << dict[s] << " ";
        else cout << s << " ";
    }
}
