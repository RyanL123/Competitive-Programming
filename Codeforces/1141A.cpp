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
    if (m%n != 0){
        cout << -1;
        return 0;
    }
    int d = m/n;
    while (d%2 == 0){
        d /= 2;
        cnt++;
    }
    while (d%3 == 0){
        d /= 3;
        cnt++;
    }
    if (d == 1) cout << cnt;
    else cout << -1;
}