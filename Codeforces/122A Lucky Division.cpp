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
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi lucky = {
            777,
            774,
            747,
            744,
            477,
            474,
            447,
            444,
            74,
            47,
            7,
            4
    };
    for (int num : lucky){
        if (n >= num && n % num == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}