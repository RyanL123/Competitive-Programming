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
        int n, a = 0, b = 0;
        cin >> n;
        int c[n+1];
        for (int i = 0; i < n; i++){
            cin >> c[i];
        }
        int l = 0, r = n-1, prev = 0, moves = 0;
        while (l <= r){
            int cur = 0;
            if (moves%2 == 0){
                while (cur <= prev && l <= r){
                    cur += c[l];
                    a += c[l];
                    l++;
                }
                prev = cur;
                moves++;
            }
            else {
                while (cur <= prev && l <= r){
                    cur += c[r];
                    b += c[r];
                    r--;
                }
                prev = cur;
                moves++;
            }
        }
        cout << moves << " " << a << " " << b << "\n";
    }
}