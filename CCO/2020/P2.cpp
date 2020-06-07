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

const int MM = 2e5+5;
vi day[MM];
int bit[MM], order[MM];

void upd(int pos, int val){
    for (int i = pos; i <= MM; i += i&-i) bit[i] += val;
}

ll q(int pos){
    ll ret = 0;
    for (int i = pos; i; i -= i&-i) ret += bit[i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        day[x].pb(i);
    }
    priority_queue<int> pq;
    for (int i = n; i > 0; i--){
        for (int j : day[i]){
            pq.push(j);
        }
        if (!pq.empty()) order[i] = pq.top();
        if (!pq.empty()) pq.pop();
    }
    if (!pq.empty()){
        cout << -1 << '\n';
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        ans += q(n) - q(order[i]-1);
        upd(order[i], 1);
    }
    cout << ans << '\n';
}