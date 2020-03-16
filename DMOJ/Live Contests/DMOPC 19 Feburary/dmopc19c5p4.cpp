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

int money[100010];
int graph[100010];
bool marked[100010];

ll find(int person){
    if (marked[person]) return money[person];
    if (graph[person] == 0 || person == graph[person]){
        return money[person];
    }
    ll total = money[person];
    total += find(graph[person]);
    marked[person] = true;
    return total;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> money[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> graph[i];
    }
    for (int i = 1; i <= n; i++){
        ll m = find(i);
        money[i] = m;
    }
    for (int i = 0; i < q; i++){
        ll p, c;
        cin >> p >> c;
        bool flag = false;
        if (p < c){
            for (int j = 1; j <= n; j++){
                if (money[j]+p >= c){
                    cout << j << endl;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) cout << -1 << endl;
    }
}