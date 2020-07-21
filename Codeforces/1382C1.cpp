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

string f(string old) {
    string ret;
    for (int i = 0; i < old.size(); i++) ret += (old[i]=='1'?'0':'1');
    reverse(all(ret));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        while (a.back() == b.back() && a.size() != 0){
            a.erase(a.size()-1), b.erase(b.size()-1);
        }
        vi ans;
        while (a != b) {
            if (a.size() == 0) break;
            if (a.front() != b.back()){
                ans.pb(a.size());
                a = f(a);
            }
            else {
                ans.pb(1);
                a[0] = (a[0]=='1'?'0':'1');
                ans.pb(a.size());
                a = f(a);
            }
            a.erase(a.size()-1), b.erase(b.size()-1);
        }
        cout << ans.size() << ' ';
        for (int i : ans) cout << i << ' ';
        cout << '\n';
    }
}