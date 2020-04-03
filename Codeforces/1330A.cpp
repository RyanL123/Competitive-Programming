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
bool A[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
    	memset(A, false, sizeof(A));
    	int n, x;
    	cin >> n >> x;
    	for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            A[a] = true;
        }
    	bool flag = false;
    	for (int i = 1; i <= 100; i++){
            if (x > 0 && !A[i]) x--;
            else if (x == 0 && !A[i]){
                cout << i-1 << "\n";
                flag = true;
                break;
            }
    	}
    	if (!flag) cout << 100 + x << "\n";
    }
}
