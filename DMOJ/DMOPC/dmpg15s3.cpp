#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int flowers[100010];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int total = 0;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        total += a;
        flowers[i] = a;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if (min(flowers[a], flowers[a+1]) < b){
            total -= min(flowers[a], flowers[a+1]);
        }
        else {
            total -= b;
        }
    }
    cout << total;
}