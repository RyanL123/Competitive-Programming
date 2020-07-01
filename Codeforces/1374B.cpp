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
        ll n, ans = 0;
        cin >> n;
        while (n != 1){
            if (n%6==0){
                n/=6;
                ans++;
            }
            else if (n%3==0){
                n/=3;
                ans+=2;
            }
            else {
                ans=-1;
                break;
            }
        }
        cout << ans << '\n';
    }
}