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

bool prime[205];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(prime, true, sizeof(prime));
    for (int i = 2; i*i <= 200; i++) {
        if (prime[i]){
            for (int j = i*i; j <= 200; j+=i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        int n, a = inf, b = inf;
        cin >> n;
        bool flag = false;
        for (int j = n+1; j <= 200; j++) {
            if (prime[j] && flag) {
                b = j;
                break;
            }
            else if (prime[j] && !flag) flag = !flag;
        }
        flag = false;
        for (int j = n-1; j > 1; j--) {
            if (prime[j] && flag) {
                a = j;
                break;
            }
            else if (prime[j] && !flag) flag = !flag;
        }
        if (a == inf) cout << b << '\n';
        else if (b == inf) cout << a << '\n';
        else if (n-a == b-n) cout << b << '\n';
        else cout << (n-a>b-n?b:a) << '\n';
    }
}