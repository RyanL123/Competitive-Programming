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
        string b;
        cin >> n >> b;
        cout << '1';
        int prevChar = 1;
        int prev = 1 + b[0] - '0';
        for (int i = 1; i < n; i++) {
            if (1+b[i]-'0' != prev) {
                cout << '1';
                prevChar = 1;
            }
            else {
                cout << '0';
                prevChar = 0;
            }
            prev = prevChar + b[i] - '0';
        }
        cout << '\n';
    }
}