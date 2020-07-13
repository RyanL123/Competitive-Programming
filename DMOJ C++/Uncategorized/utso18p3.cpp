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

const int MM = 1e6+5;
bool b[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, k, v;
    cin >> n >> t >> k >> v;
    for (int i = 0, x; i < v; i++){
        cin >> x;
        b[x] = true;
    }
    int cnt = 0, ans = 0;
    deque<int> dq;
    for (int i = 1; i < t; i++){
        if (!b[i]) dq.push_back(i);
        else cnt++;
    }
    for (int i = t; i <= n; i++){
        cnt -= b[i-t];
        if (!b[i]) dq.push_back(i);
        else cnt++;
        while (!dq.empty() && dq[dq.size()-1] < i-t){
            dq.pop_front();
        }
        while (cnt < k){
            ans++, cnt++;
            b[dq[dq.size()-1]] = true;
            dq.pop_back();
        }
    }
    cout << ans << "\n";
}