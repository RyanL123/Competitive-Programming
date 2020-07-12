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
        int n, m = 1;
        cin >> n;
        int ans = n-1;
        for (int i = 2; i <= ceil(sqrt(n)); i++){
            if (n%i==0){
                if (max(i, n-i) < ans){
                    ans = max(i, n-i);
                    m = i;
                }
                if (max(n/i, n-n/i) < ans){
                    ans = max(n/i, n-n/i);
                    m = n/i;
                }
            }
        }
        cout << n-m << ' ' << m << '\n';
    }
}