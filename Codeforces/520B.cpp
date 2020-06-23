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

const int MM = 1e4+5;
int d[2*MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (m<=n) cout << n-m << '\n';
    else {
        queue<int> q;
        q.push(n);
        fill(d, d+MM, inf);
        d[n] = 0;
        while (!q.empty()){
            int t = q.front();
            q.pop();
            if (t*2 <= 2*m && d[t*2] > d[t]+1){
                d[t*2] = d[t]+1;
                q.push(t*2);
            }
            if (d[t-1] > d[t]+1){
                d[t-1] = d[t]+1;
                q.push(t-1);
            }
        }
        cout << d[m] << '\n';
    }
}