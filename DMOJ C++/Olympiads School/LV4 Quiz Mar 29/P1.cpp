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
    int t, n;
    cin >> t >> n;
    vii vec;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        vec.pb(mp(abs(x), x));
    }
    sort(vec.begin(), vec.end());
    int prev = 0, count = 0;
    for (int i = 0; i < n; i++){
        if (t - abs(prev - vec[i].second) >= 0){
            t -= abs(prev - vec[i].second);
            prev = vec[i].second;
            count++;
        }
        else break;
    }
    cout << count;
}