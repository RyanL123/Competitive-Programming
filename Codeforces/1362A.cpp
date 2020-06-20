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
        ull a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        ll x = 0, y = 0;
        while (a%2==0) {
            a/=2;
            x++;
        }
        while (b%2==0){
            b/=2;
            y++;
        }
        cout << (a==b?ceil((double)abs(x-y)/3):-1) << '\n';
    }
}