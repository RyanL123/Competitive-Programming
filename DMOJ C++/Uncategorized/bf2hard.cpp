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

ull hsh[1000010], pw[1000010], base = 131, m = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k, l = 0;
    cin >> s >> k;
    int n = s.length();
    pw[0] = 1;
    for (int i = 1; i <= k; i++){
    	hsh[i] = ((hsh[i-1]%m * base%m)%m + (s[i-1]-'a')%m)%m;
    	pw[i] = (pw[i-1]%m * base%m)%m;
    }
    ull cur = hsh[k]%m, lowest = cur;
    for (int i = k; i <= n; i++){
        hsh[i] = ((hsh[i-1]%m*base%m)%m + (s[i-1]-'a')%m)%m;
        cur = (hsh[i]%m - (hsh[i-k]%m*pw[k]%m)%m)%m;
        if (cur < lowest){
            l = i-k;
            lowest = cur;
        }
    }
    cout << s.substr(l, k);
}
