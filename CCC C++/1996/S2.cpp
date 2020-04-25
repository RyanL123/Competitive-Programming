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

string subtract(string s, char n){
    int last = s[s.length()-1] - '0';
    int cur = n - '0';
    if (last >= cur) return s.substr(0, s.length()-1) + (char)(last - cur + '0');
    int ptr = s.length()-2;
    while (s[ptr] == '0' && ptr >= 0){
        s[ptr] = '9';
        ptr--;
    }
    s[ptr]--;
    while (s[0] == '0') s.erase(0, 1);
    return s.substr(0, s.length()-1) + (char)(last + 10 - cur + '0');
}

void solve(string s, string o){
    cout << s << "\n";
    while (s.length() > 2){
        char last = s[s.length()-1];
        s = subtract(s.substr(0, s.length()-1), last);
        cout << s << "\n";
    }
    int cnt = (s[0]-'0')*10+(s[1]-'0');
    if (cnt%11 == 0) cout << "The number " + o + " is divisible by 11.\n\n";
    else cout << "The number " + o + " is not divisible by 11.\n\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        solve(s, s);
    }
}
