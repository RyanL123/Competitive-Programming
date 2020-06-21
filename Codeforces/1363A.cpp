#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, x;
        cin >> n >> x;
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++){
            int y;
            cin >> y;
            if (y%2==1)odd++;
            else even++;
        }
        if (odd==0) cout << "No\n";
        else {
            bool flag = false;
            for (int i = 0; i <= min(even, x); i++){
                if (min((x-i), odd)%2==1){
                    flag = true;
                    break;
                }
            }
            cout << (flag?"Yes":"No") << '\n';
        }
    }
}