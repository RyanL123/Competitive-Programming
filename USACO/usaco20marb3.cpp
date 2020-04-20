#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int cnt[101];
bool mrk[101], done[101];

struct e{
    int t, x, y;
};

bool cmp(e a, e b){
    return a.t < b.t;
}

string s;
bool check(){
    for (int i = 1; i <= s.length(); i++){
        if (s[i-1] == '0' && mrk[i]) return false;
        if (s[i-1] == '1' && !mrk[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, T, lo = inf, hi = 0, tot = 0;
    cin >> n >> T >> s;
    vector<e> v;
    for (int i = 0; i < T; i++){
        int t, x, y;
        cin >> t >> x >> y;
        v.push_back({t,x,y});
    }
    sort(v.begin(), v.end(), cmp);
    for (int j = 1; j <= n; j++){
        for (int i = 0; i <= T; i++){
            memset(cnt, 0, sizeof(cnt));
            memset(mrk, false, sizeof(mrk));
            mrk[j] = true;
            for (e E : v){
                if (mrk[E.x] && mrk[E.y]){
                    cnt[E.x]++;
                    cnt[E.y]++;
                }
                else if (mrk[E.x] && cnt[E.x]+1 <= i){
                    mrk[E.y] = true;
                    cnt[E.x]++;
                }
                else if (mrk[E.y] && cnt[E.y]+1 <= i){
                    mrk[E.x] = true;
                    cnt[E.y]++;
                }
            }
            if (check()){
                if (!done[j]){
                    tot++;
                    done[j] = true;
                }
                lo = min(lo, i);
                hi = max(hi, i);
            }
        }
    }
    cout << tot << " ";
    if (lo == inf) cout << "0 ";
    else cout << lo << " ";
    if (hi >= T) cout << "Infinity";
    else cout << hi;
}