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
        int n;
        string s;
        cin >> n >> s;
        int zero = -1, one = -1;
        for (int i = n-1; i >= 0; i--){
            if (s[i] == '0'){
                zero = i;
                break;
            }
        }
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                one = i;
                break;
            }
        }
        if (zero <= one || zero == -1 || one == -1) cout << s << '\n';
        else cout << s.substr(0, one) << s.substr(zero, n) << "\n";
    }
}