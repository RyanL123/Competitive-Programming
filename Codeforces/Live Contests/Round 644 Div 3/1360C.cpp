#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vi even, odd;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (x%2==0) even.pb(x);
            else odd.pb(x);
        }
        if (even.size()%2==odd.size()%2&&even.size()%2==0){
            cout << "YES\n";
        }
        else if (even.size()%2!=odd.size()%2){
            cout << "NO\n";
        }
        else {
            bool flag = false;
            for (int i = 0; i < even.size(); i++){
                for (int j = 0; j < odd.size(); j++){
                    if (abs(even[i] - odd[j]) == 1){
                        flag = true;
                    }
                }
            }
            if (flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
