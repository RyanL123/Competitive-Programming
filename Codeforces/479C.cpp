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

bool cmp(pii a, pii b){
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vii v;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.eb(a, b);
    }
    sort(all(v), cmp);
    int prev = min(v[0].first, v[0].second);
    for (int i = 1; i < n; i++){
        if (min(v[i].first, v[i].second) >= prev){
            prev = min(v[i].first, v[i].second);
        }
        else prev = max(v[i].first, v[i].second);
    }
    cout << prev << '\n';
}
