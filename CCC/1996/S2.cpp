#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

string subtract(string s, int n){
    int ones = s[s.length()-1]-48;
    int tens = (s[s.length()-1]-48)*10;
    if (n <= ones){
        char result = (char)(ones-n+48);
        return s.substr(0, s.length()-1)+result;
    }
    else {
        int remainder = tens+ones-n;
        if (remainder > 9){

        }
        else {
            
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n;
    while (n--){
        cin >> s;

    }
}
