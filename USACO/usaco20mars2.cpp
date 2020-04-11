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

pii fav[100005];
int ans[100005], taken[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int f, s;
        cin >> f >> s;
        fav[i] = {f,s};
    }
    int cnt = 0;
    memset(taken, -1, sizeof(taken));
    for (int i = n-1; i >= 0; i--){
        int f = fav[i].first;
        int j = i;
        while (true){
            // Cereal not taken by any cow
            if (taken[f] == -1){
                taken[f] = j;
                cnt++;
                break;
            }
            // Cereal taken by earlier cow
            else if (taken[f] < j) break;
            else {
                int cow = taken[f]; // Later cow that took cereal
                taken[f] = j; // Give it to the earlier cow
                if (f == fav[cow].second) break; // Later cow cannot get anything
                j = cow;
                f = fav[cow].second; // Later cow's second choice isn't taken. Recurse with this cow as priority
            }
        }
        ans[i] = cnt;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << "\n";
}
