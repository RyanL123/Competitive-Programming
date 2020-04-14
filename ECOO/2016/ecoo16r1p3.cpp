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

bool check(vi v){
    for (int i = 0; i < v.size()-1; i++){
        if (v[i+1] < v[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++){
        int n, ans = 0;
        cin >> n;
        vi v;
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            v.pb(x);
        }
        while (!check(v)){
            int prev = 0, mx = 0, mxInd = 0;
            for (int j = 0; j < n; j++){
                if (v[j] > prev) prev = v[j];
                else if (v[j] > mx){
                    mx = v[j];
                    mxInd = j;
                }
            }
            v.erase(v.begin() + mxInd);
            v.insert(v.begin(), mx);
            ans += mxInd;
        }
        cout << ans << "\n";
    }
}