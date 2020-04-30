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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    // 1 = o.
    // 2 = oo
    // 3 = .o
    // 4 = ..
    string a[3] = {
            "11221221331122122133113221",
            "41433122124143312212412433",
            "44444444441111111111223222"
    };
    getline(cin, s);
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' ') cout << "..";
            else {
                switch (a[j][s[i] - 'A']){
                    case ('1'): cout << "o.";
                    break;
                    case ('2'): cout << "oo";
                    break;
                    case ('3'): cout << ".o";
                    break;
                    case ('4'): cout << "..";
                    break;
                }
            }
        }
        cout << '\n';
    }
}
