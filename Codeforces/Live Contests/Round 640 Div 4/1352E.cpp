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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int l = 0, r = 0; r < n; r++){
                sum += a[r];
                while (sum > a[i] && r-l > 1){
                    sum -= a[l];
                    l++;
                }
                if (sum == a[i] && r-l >= 1){
                    ans++;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}