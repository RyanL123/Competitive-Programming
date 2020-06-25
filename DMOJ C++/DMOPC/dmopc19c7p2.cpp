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

int a[1000005], n;
struct q{
    int l, r, t;
};
vii shifted;
vector<q> ans;

bool check(vii copy){
    for (pii p : copy){
        if (p.first != 0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int mn = 0, tot = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < a[mn]) mn = i;
    }
    for (int i = mn; i < n; i++) shifted.pb(mp(a[i], i));
    for (int i = 0; i < mn; i++) shifted.pb(mp(a[i], i));
    for (int i = 0; i <= a[mn]; i++){
        tot = 0;
        vii copy(shifted);
        copy[n-1].first -= i;
        copy[0].first -= i;
        ans.pb({copy[0].second, copy[n-1].second, i});
        tot += i;
        for (int j = 0; j < n-1; j++){
            ans.pb({copy[j].second, copy[j+1].second, copy[j].first});
            copy[j+1].first -= copy[j].first;
            if (copy[j+1].first < 0) goto skip;
            tot += copy[j].first;
            copy[j].first = 0;
        }
        if (check(copy)){
            cout << "YES\n" << tot << '\n';
            for (q p : ans) {
                for (int j = 0; j < p.t; j++) cout << p.l << ' ' << p.r << '\n';
            }
            return 0;
        }
        skip:
        ans.clear();
    }
    cout << "NO\n";
}