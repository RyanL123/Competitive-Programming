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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n, m = 1e9+7, ans = 1, a = 1;
    cin >> n;
    for (int i = 0; i < n; i++){
        ans = (ans%m * 27%m)%m;
        a = (a%m * 7%m)%m;
    }
    cout << (ans-a+m)%m;
}
