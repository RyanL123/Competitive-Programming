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

int f(string s, char c){
    if (s.size() == 1) return (s[0] != c);
    int x = f(s.substr(0, s.size()/2), c+1);
    int y = f(s.substr(s.size()/2, s.size()/2), c+1);
    for (int i = 0; i < s.size()/2; i++){
        y += (c != s[i]);
    }
    for (int i = s.size()/2; i < s.size(); i++){
        x += (c != s[i]);
    }
    return min(x, y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        cout << f(s, 'a') << '\n';
    }
}