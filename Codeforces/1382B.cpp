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
        bool a[n];
        int turn = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            a[i] = (x != 1);
        }
        bool cur = true;
        for (int i = n-2; i >= 0; i--) {
            if (!a[i]) cur = !cur;
            else cur = true;
        }
        if (cur) cout << "First\n";
        else cout << "Second\n";
    }
}