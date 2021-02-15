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

const int MM = 5e4+5;
bool prime[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    memset(prime, true, sizeof(prime));
    for (int i = 2; i*i <= MM; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= MM; j += i) prime[j] = false;
        }
    }
    while (t--) {
        int d;
        cin >> d;
        int a = 1, cnt = 1, prev = 1+d, cur = 1+d;
        while (cnt < 3) {
            if (prime[cur]) {
                prev = cur;
                a *= cur;
                cnt++;
                cur += d;
            }
            else cur++;
        }
        cout << a << "\n";
    }
}