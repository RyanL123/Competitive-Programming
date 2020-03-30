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

int base = 131;
ll hash1[1000010], hash2[1000010], pw[1000010];

ll subHash(int l, int r, ll hash[]){
	return hash[r] - hash[l-1]*pw[r-l+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;	
    cin >> a >> b;
    pw[0] = 1;
    for (int i = 1; i <= a.length(); i++){
    	hash1[i] = hash1[i-1]*base + a[i-1];
    	pw[i] = pw[i-1]*base;
    }
    for (int i = 1; i <= b.length(); i++){
    	hash2[i] = hash2[i-1]*base + b[i-1];
    	pw[i] = pw[i-1]*base;
    }
    ll end;
    for (int i = 1; i <= min(a.length(), b.length()); i++){
    	ll A = subHash(a.length()-i+1, a.length(), hash1);
    	ll B = subHash(1, i, hash2);
    	if (A == B) end = i;
    }
    cout << a.substr(0, a.length()-end) + b << endl;
}
