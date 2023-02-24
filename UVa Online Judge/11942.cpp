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
    int n;
    cin >> n;
    cout << "Lumberjacks:" << endl;
    while (n--) {
        vi v(10);
        for (int i = 0; i < 10; i++) cin >> v[i];
        vi a = v, b = v;
        sort(all(a), greater<int>());
        sort(all(b), less<int>());
        if (a == v || b == v) cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }
}