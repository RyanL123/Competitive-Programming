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
    while (t--){
        int a, b, n;
        cin >> a >> b >> n;
        if (b < a) swap(a, b);
        int cnt = 0;
        while (a+b <= n){
            a += b;
            cnt++;
            swap(a, b);
        }
        cnt++;
        cout << cnt << '\n';
    }
}