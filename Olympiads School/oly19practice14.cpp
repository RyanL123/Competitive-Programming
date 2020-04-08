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

int l[1000010], r[1000010], a[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    l[0] = a[0];
    r[n-1] = a[n-1];
    for (int i = 1; i < n; i++){
        l[i] = max(l[i-1], a[i]);
    }
    for (int i = n-2; i >= 0; i--){
        r[i] = max(r[i+1], a[i]);
    }
    ll rain = 0;
    for (int i = 0; i < n; i++){
        rain += max(min(l[i], r[i])-a[i], 0);
    }
    cout << rain;
}
