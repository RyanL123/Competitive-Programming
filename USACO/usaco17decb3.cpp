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

struct e{
    int d, c, ind;
};

bool cmp(e x, e y){
    return x.d < y.d;
}

int score[3], mask = 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N;
    cin >> N;
    vector<e> v;
    for (int i = 0; i < N; i++) {
        int d, c, ind; string s;
        cin >> d >> s >> c;
        if (s == "Mildred") ind = 0;
        else if (s == "Bessie") ind = 1;
        else ind = 2;
        v.pb({d, c, ind});
    }
    sort(all(v), cmp);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        e r = v[i];
        score[r.ind] += r.c;
        int nmask = 0, mx = max(score[0], max(score[1], score[2]));
        for (int i = 0; i < 3; i++) {
            if (score[i] == mx) nmask |= 1<<i;
        }
        ans += (nmask != mask);
        mask = nmask;
    }
    cout << ans << '\n';
}