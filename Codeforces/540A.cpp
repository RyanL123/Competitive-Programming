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
    int n, cnt = 0;
    string s1, s2;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++){
        int diff = abs((int)s1[i] - (int)s2[i]);
        cnt += min(diff, 10-diff);
    }
    cout << cnt;
}
