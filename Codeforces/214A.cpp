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
    int n, m, cnt = 0;
    cin >> n >> m;
    int sq = floor(sqrt(n));
    for (int a = sq; a >= 0; a--){
        int b = n-a*a;
        if (a + b*b == m){
            cnt++;
        }
    }
    cout << cnt;
}