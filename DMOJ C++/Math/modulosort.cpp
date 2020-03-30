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

vi mod[10000010];
bool active[10000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        int a = m%k;
        mod[a].pb(m);
        active[a] = true;
    }
    for (int i = 0; i <= k; i++){
        if (active[i]){
            sort(mod[i].begin(), mod[i].end());
            for (int j : mod[i]){
                cout << j << " ";
            }
        }
    }
}
