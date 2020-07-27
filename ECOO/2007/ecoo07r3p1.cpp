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

const int MM = 1e7+5;
bool prime[MM];
pii get(int n) {
    for (int i = n/2; i >= 3; i--) {
        if (prime[i] && prime[n-i]) {
            return {i, n-i};
        }
    }
    return {-1, -1};
}
void solve(int n){
    if (prime[n]) {
        cout << n << " = " << n << '\n';
        return;
    }
    pii ans = get(n);
    if (ans.first != -1) cout << n << " = " << ans.first << " + " << ans.second << '\n';
    else {
        for (int i = n/3; i >= 3; i--) {
            if (prime[i]) {
                ans = get(n-i);
                if (ans.first < i) continue;
                else {
                    cout << n << " = " << i << " + " << ans.first << " + " << ans.second << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(prime, true, sizeof(prime));
    for (int i = 2; i*i < MM; i++) {
        if (prime[i]) {
            for (int j = i*i; j < MM; j+=i) {
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        solve(n);
    }
}