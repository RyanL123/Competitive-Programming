#include <bits/stdc++.h>
#include <numeric>
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

int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v.pb(x);
    }
    int g = abs(v[1]-v[0]);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            g = gcd(g, abs(v[i]-v[j]));
        }
    }
    set<int> ans;
    for (int i = 2; i*i <= g; i++) {
        if (g%i==0){
            ans.insert(i), ans.insert(g/i);
        }
    }
    for (int i : ans) cout << i << ' ';
    cout << g << "\n";
}