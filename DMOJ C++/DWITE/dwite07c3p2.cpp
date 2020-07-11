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
    for (int i = 0; i < 5; i++){
        string s;
        getline(cin, s);
        int n = s.size(), ptr = 0;
        char prev = '!';
        bool first = true;
        while (ptr < n){
            if (s[ptr] == '/' && prev == '/' && ptr+1 < n){
                if (!first) cout << ' ';
                cout << s.substr(ptr+1, n);
                first = false;
                break;
            }
            else if (s[ptr] == '"'){
                if (!first) cout << ' ';
                ptr++;
                while (ptr < n && s[ptr] != '"'){
                    cout << s[ptr];
                    ptr++;
                }
                first = false;
            }
            else if (s[ptr] == '\''){
                if (!first) cout << ' ';
                ptr++;
                while (ptr < n && s[ptr] != '\''){
                    cout << s[ptr];
                    ptr++;
                }
                first = false;
            }
            else if (s[ptr] == '*' && prev == '/'){
                if (!first) cout << ' ';
                ptr++;
                while (ptr+1 < n && !(s[ptr] == '*' && s[ptr+1] == '/')){
                    cout << s[ptr];
                    ptr++;
                }
                first = false;
            }
            prev = s[ptr];
            ptr++;
        }
        cout << '\n';
    }
}