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
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    cout << 2*(n-1) + m-1 + (n) * (m-1)<< endl;
    for (int i = 1; i < n; i++){
    	cout << "U";
    }
    for (int i = 1; i < m; i++){
    	cout << "L";
    }
    for (int i = 1; i <= n; i++){
    	if (i%2 == 1) for (int j = 1; j < m; j++) cout << "R";
    	else for (int j = 1; j < m; j++) cout << "L";
    	if (i != n) cout << "D";
    }
}