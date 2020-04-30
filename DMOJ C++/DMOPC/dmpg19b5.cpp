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

struct p{
    int x, y, c, id;
};

bool cmp(p a, p b){
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<p> v;
    for (int i = 1; i <= n; i++){
        int x, y, c;
        cin >> x >> y >> c;
        v.pb({x, y, c, i});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n-2; i++){
        if (v[i].c == v[i+1].c && v[i+1].c == v[i+2].c && v[i].c == v[i+2].c) continue;
        else {
            cout << v[i].id << " " << v[i+1].id << " " << v[i+2].id;
            return 0;
        }
    }
    cout << -1;
}
