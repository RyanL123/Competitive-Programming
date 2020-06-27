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
        string s;
        cin >> s;
        int n = s.size();
        if (s == string(n, '1') || s == string(n, '0')) cout << s << '\n';
        else {
            for (int i = 0; i < s.size(); i++){
                if (s[0] == '1') cout << "10";
                else cout << "01";
            }
            cout << "\n";
        }
    }
}