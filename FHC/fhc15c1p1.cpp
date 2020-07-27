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
ll cnt[MM];
void solve(int id) {
    int ans = 0, A, B, K;
    cin >> A >> B >> K;
    for (int i = A; i <= B; i++) {
        ans += (cnt[i] == K);
    }
    cout << "Case #" << id << ": " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    memset(prime, true, sizeof(prime));
    for (int i = 2; i < MM; i++) {
        if (prime[i]) {
            for (int j = i; j < MM; j+=i) {
                prime[j] = false;
                cnt[j]++;
            }
        }
    }
    for (int i = 1; i <= t; i++) solve(i);
}