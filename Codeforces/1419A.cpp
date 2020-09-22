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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n%2==1) {
            bool win = false;
            for (int i = 0; i < n; i+=2) {
                if ((s[i]-'0')%2==1) win = true;
            }
            cout << (win?"1\n":"2\n");
        }
        else {
            bool win = true;
            for (int i = 1; i < n; i+=2) {
                if ((s[i]-'0')%2==0) win = false;
            }
            cout << (win?"1\n":"2\n");
        }
    }
}