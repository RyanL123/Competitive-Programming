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
vii ans;
int active, done;

bool adj(int i, int j){
    if (a[i] == a[j] && a[i] != 0){
        for (int k = 0; k < a[i]; k++) ans.pb(mp(i, j));
        a[i] = a[j] = 0;
        done += 2;
        return true;
    }
    return false;
}

bool sub(int i, int j, int k){
    if (a[i] - a[j] == a[k] && a[i] != 0 && a[j] != 0 && a[k] != 0){
        for (int x = 0; x < a[j]; x++) ans.pb(mp(i, j));
        for (int x = 0; x < a[i]; x++) ans.pb(mp(i, k));
        a[i] = a[j] = a[k] = 0;
        done += 3;
        return true;
    }
    return false;
}

bool check(){
    if (adj(0, n-1)) return true;
    else if (sub(n-1, 0, n-2) || sub(n-1, n-2, 0)) return true;
    else if (sub(0, 1, n-1) || sub(0, n-1, 1)) return true;
    for (int i = 0; i < n-1; i++){
        if (adj(i, i+1)) return true;
        else if (i != 0 && sub(i, i-1, i+1)) return true;
        else if (i != 0 && sub(i, i+1, i-1)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] != 0) active++;
    }
    int prev = done;
    while (done != active){
        if (!check()) break;
        else if (prev == done){
            cout << "NO\n";
            return 0;
        }
        prev = done;
    }
    if (done == active){
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (pii p : ans) cout << p.first << " " << p.second << '\n';
    }
    else cout << "NO\n";
}