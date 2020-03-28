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

ll hsh[200010], pw[200010], base = 131;
int fs[26], ft[26];
unordered_set<ll> st;

bool check(){
    for (int i = 0; i < 26; i++){
        if (fs[i] != ft[i]) return false;
    }
    return true;
}

ll getSubHash(int l, int r){
    return hsh[r] - hsh[l-1]*pw[r-l+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 1; i <= n; i++){
        fs[s[i-1]-'a']++;
    }
    pw[0] = 1;
    // Generate hash which can be calculated with sliding window
    // Kind of like prefix sum array
    for (int i = 1; i <= m; i++){
        hsh[i] = hsh[i-1]*base + t[i-1];
        pw[i] = pw[i-1]*base;
    }
    for (int i = 1; i <= m; i++){
        // Sliding window
        ft[t[i-1]-'a']++;
        if (i < n) continue;
        if (i > n) ft[t[i-n-1]-'a']--;
        // Rolling hash
        if (check()) st.insert(getSubHash(i-n+1, i));
    }
    cout << st.size() << endl;
}
