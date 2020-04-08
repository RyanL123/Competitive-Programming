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

ll psa[1000010];
map<ll, ll> mod;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, len = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i]%=k;
        psa[i] += psa[i-1];
        psa[i]%=k;
    }
    for (int i = 1; i <= n; i++){
        if (psa[i] == 0){
            len = i;
        }
        else if (mod[psa[i]] == 0){
            mod[psa[i]] = i;
        }
        else {
            len = max(len, i - mod[psa[i]]);
        }
    }
    cout << len;
}
