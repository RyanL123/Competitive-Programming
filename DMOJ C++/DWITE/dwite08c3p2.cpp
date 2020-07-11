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
        int cur = 0, cnt = 0;
        for (int j = 0; j < s.size(); j++){
            if (!isalpha(s[j])) {
                cur += (cnt >= 4);
                cnt = 0;
            }
            else cnt++;
        }
        cur += (cnt >= 4);
        cout << cur << '\n';
    }
}