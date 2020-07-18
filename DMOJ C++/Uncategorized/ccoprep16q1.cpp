#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

// Max area under histogram
int solve(int a[], int n) {
    int ret = 0;
    stack<int> s;
    int i = 0;
    while (i < n) {
        if (s.empty() || a[i] >= a[s.top()]) {
            s.push(i);
            i++;
        }
        else {
            int top = s.top();
            s.pop();
            if (s.empty()) ret = max(ret, a[top]*i);
            else ret = max(ret, a[top]*(i-s.top()-1));
        }
    }
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (s.empty()) ret = max(ret, a[top]*i);
        else ret = max(ret, a[top]*(i-s.top()-1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    while (k--){
        int n, m, ans = 0;
        cin >> m >> n;
        int grid[m+1][n+1];
        memset(grid, 0, sizeof(grid));
        for (int i = 1; i <= m; i++){
            for (int j = 0; j < n; j++){
                char c;
                cin >> c;
                if (c == 'F') grid[i][j] = grid[i-1][j]+1;
            }
            ans = max(ans, solve(grid[i], n));
        }
        cout << ans*3 << '\n';
    }
}