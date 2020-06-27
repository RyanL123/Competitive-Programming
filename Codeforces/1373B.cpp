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
        int zero = 0, one = 0;
        for (int i = 0; i < s.size(); i++){
            zero += (s[i] == '0');
            one += (s[i] == '1');
        }
        if (min(zero, one)%2==0) cout << "NET\n";
        else cout << "DA\n";
    }
}