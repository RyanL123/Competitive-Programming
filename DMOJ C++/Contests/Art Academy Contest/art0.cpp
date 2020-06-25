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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        int l = s.length();
        for (int i = 0; i < l; i++){
            if (s[i] == 'A' || s[i] == 'a') cout << "Hi! ";
            else if (s[i] == 'e' || s[i] == 'E') cout << "Bye! ";
            else if (s[i] == 'i' || s[i] == 'I') cout << "How are you? ";
            else if (s[i] == 'o' || s[i] == 'O') cout << "Follow me! ";
            else if (s[i] == 'u' || s[i] == 'U') cout << "Help! ";
            else if (isdigit(s[i])) cout << "Yes! ";
        }
        cout << "\n";
    }
}