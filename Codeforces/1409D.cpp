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
    while (t--) {
        string n, ans;
        int s;
        cin >> n >> s;
        int tot = 0, ind = -1;
        for (int i = 0; i < n.size(); i++) {
            if (tot + n[i]-'0' + 1 > s && ind == -1) ind = i;
            tot += n[i]-'0';
        }
        if (tot <= s) {
            cout << "0\n";
            continue;
        }
        bool carry = false;
        for (int i = n.size()-1; i >= ind; i--) {
            if (n[i] == '0' && carry) ans += '9';
            else if (n[i] == '0') ans += '0', carry = false;
            else if (carry) ans += '0'+(9-(n[i]-'0')), carry = true;
            else ans += '0'+(10-(n[i]-'0')), carry = true;
        }
        while (ans.back() == '0') ans.erase(ans.size()-1);
        reverse(all(ans));
        cout << ans << '\n';
    }
}