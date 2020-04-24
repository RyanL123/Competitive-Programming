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

void check(char &c){
    if (c == '9') c--;
    else c++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        string s[9];
        for (int i = 0; i < 9; i++){
            cin >> s[i];
        }
        check(s[0][0]);
        check(s[1][3]);
        check(s[2][8]);
        check(s[3][1]);
        check(s[4][4]);
        check(s[5][7]);
        check(s[6][2]);
        check(s[7][5]);
        check(s[8][6]);
        for (int i = 0; i < 9; i++){
            cout << s[i] << "\n";
        }
    }
}