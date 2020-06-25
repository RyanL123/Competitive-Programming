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
    string s;
    cin >> s;
    int n = s.size();
    string c = string(n, '0');
    int mx = 0;
    for (int i = 0; i < n; i++){
        mx = max(mx, (int)s[i]);
    }
    cout << mx-'0' << '\n';
    while (s != c){
        string o;
        for (int i = 0; i < n; i++){
            if (s[i] != '0'){
                o += '1';
                s[i]--;
            }
            else o += '0';
        }
        int ptr = 0;
        while (o[ptr] == '0') ptr++;
        cout << o.substr(ptr, n) << ' ';
    }
    
}