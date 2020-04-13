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
    vi vec;
    for (int i = 0; i < 9; i++){
        int x;
        cin >> x;
        vec.pb(x);
    }
    sort(vec.begin(), vec.end());
    while (next_permutation(vec.begin(), vec.end())){
        if (accumulate(vec.begin(), vec.begin()+7, 0) == 100){
            for (int i = 0; i < 7; i++){
                cout << vec[i] << "\n";
            }
            return 0;
        }
    }
}
