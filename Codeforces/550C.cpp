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

bool check(char a, char b, char c){
    return ((a-'0')*100+(b-'0')*10+(c-'0'))%8==0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++){
        if (s[i] == '0' || s[i] == '8'){
            cout << "YES\n";
            cout << s[i];
            return 0;
        }
    }
    if (n == 2){
        if (check('0', s[0], s[1])){
            cout << "YES\n";
            cout << s << "\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                if (check(s[i], s[j], s[k])){
                    cout << "YES\n";
                    cout << s.substr(0, i+1) << s[j] << s[k] << '\n';
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (check('0', s[i], s[j])){
                cout << "YES\n";
                cout << s[i] << s[j] << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
}