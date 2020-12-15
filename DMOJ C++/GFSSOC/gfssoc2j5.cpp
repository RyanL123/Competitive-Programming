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

const int MM = 5e5+5;
int N, Q, a[MM], pfx[MM], sfx[MM], pcnt[MM], scnt[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) {
        pcnt[i] = pcnt[i-1];
        pfx[i] = pfx[i-1];
        if (a[i] > pfx[i]) pfx[i] = a[i], pcnt[i] = 1;
        else if (a[i] == pfx[i]) pcnt[i]++;
    }
    for (int i = N; i >= 1; i--) {
        scnt[i] = scnt[i+1];
        sfx[i] = sfx[i+1];
        if (a[i] > sfx[i]) sfx[i] = a[i], scnt[i] = 1;
        else if (a[i] == sfx[i]) scnt[i]++;
    }
    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        if (pfx[a-1] > sfx[b+1]) cout << pfx[a-1] << ' ' << pcnt[a-1] << '\n';
        else if (sfx[b+1] > pfx[a-1]) cout << sfx[b+1] << ' ' << scnt[b+1] << '\n';
        else cout << pfx[a-1] << ' ' << pcnt[a-1]+scnt[b+1] << '\n';
    }
}