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
    vii v;
    for (int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        v.eb(x, h);
    }
    srt(v);
    int ans = 0, prev = -inf;
    for (int i = 0; i < n; i++){
        if (v[i].first - v[i].second > prev){
            prev = v[i].first;
            ans++;
        }
        else if (i < n-1 && v[i].first+v[i].second < v[i+1].first){
            prev = v[i].first + v[i].second;
            ans++;
        }
        else if (i == n-1) ans++;
        else prev = v[i].first;
    }
    cout << ans << '\n';
}