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

const int MOD = 1e9+7;

int solve(int n, int k){
	if (n == 0 || k == 0) return 1;
	if (k < 0) return 0;
	if (n >= pow(2, k)){
		return (solve(n-pow(2,k), k)%MOD + solve(n, k-1)%MOD)%MOD;
	}
	return solve(n, k-1)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n, floor(log2((double)n)));
}
