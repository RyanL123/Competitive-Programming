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
    int n, X = 0, Y = 0, Z = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        X += x, Y += y, Z += z;
    }
    cout << (X==0&&Y==0&&Z==0?"YES":"NO") << '\n';
}