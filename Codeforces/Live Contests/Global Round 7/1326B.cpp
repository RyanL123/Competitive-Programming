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

int b[200010];
int a[200010];
int x[200010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    a[0] = b[0];
    a[1] = b[1]+a[0];
    x[1] = a[0];
    for (int i = 2; i < n; i++){
        x[i] = max(x[i-1], a[i-1]);
        a[i] = b[i]+x[i];
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}