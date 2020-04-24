#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 2; i <= 30; i++){
            if (n % ((int)pow(2, i)-1) == 0){
                int ans = n/(pow(2, i)-1);
                printf("%d\n", ans);
                break;
            }
        }
    }
}