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

const int MM = 3e3+5;
void solve(int n) {
    while (n%2==0) {
        n /= 2;
        cout << "2 ";
    }
    for (int i = 3; i*i <= n; i+=2) {
        while (n%i==0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 2) cout << n << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        solve(x);
        cout << "\n";
    }
}