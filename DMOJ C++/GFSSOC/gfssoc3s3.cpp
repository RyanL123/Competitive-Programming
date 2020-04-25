#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, ans = 0;
    cin >> n;
    if (n+1 >= 18 || n < 0){
        cout << 999999998;
    }
    else {
        if (n%2==0){
            n/=2;
            for (int i = 0; i < n; i++){
                ans += pow(10, i)*9*2;
            }
        }
        else {
            n = (n+1)/2;
            for (int i = 0; i < n; i++){
                ans += pow(10, i)*9*2;
            }
            ans -= pow(10, max(0LL, n-1))*9;
        }
        cout << ans;
    }
}
