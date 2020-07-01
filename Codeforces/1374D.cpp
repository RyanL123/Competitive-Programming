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

// Find required amount to make divisible by K
// Sort required amount from least to greatest
// If there are two of the same required, add K to prevent dupes
// Currently TLEs on case 5

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, k, ans = 0, x = 0;
        cin >> n >> k;
        int a[n];
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pq.push((a[i]%k==0?0:k-(a[i]%k)));
        }
        int prev = -1;
        while (!pq.empty()){
            int b = pq.top();
            pq.pop();
            if (b == 0) continue;
            else if (b == prev){
                pq.push(b+k);
            }
            else {
                int req = abs(k-b);
                cout << "req: " << req << ' ';
                ans += req-x+1;
                x = req+1;
                cout << "x: " << x << ' ';
                prev = b;
            }
        }
        cout << '\n';
        cout << ans << "\n";
    }
}