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
        int n, cnt = 0, cur = 1;
        cin >> n;
        vi ans;
        while (n > 0){
            if (n%10 != 0) {
                ans.pb((n%10)*cur);
                cnt++;
            }
            n = (n-n%10)/10;
            cur *= 10;
        }
        cout << cnt << '\n';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }
}