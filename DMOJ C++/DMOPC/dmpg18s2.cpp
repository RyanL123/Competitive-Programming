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
#define inf 0x3f3f3f3f

ll psa[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> psa[i];
        psa[i] += psa[i-1];
    }
    ll sum = 0;
    int l = 1, r = n;
    for (int i = 1; i <= n; i++){
        while (l < i){
            l++, r--;
        }
        sum += psa[r] - psa[l-1];
        cout << sum << '\n';
    }
}