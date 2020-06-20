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

bool solve(int k, const int a[], const int frq[], int n){
    int frq2[1025];
    memset(frq2, 0, sizeof(frq2));
    for (int i = 0; i < n; i++){
        int cur = a[i]^k;
        if (cur > 2014) return false;
        frq2[cur]++;
        if (frq2[cur] != frq[cur]) return false;
    }
    for (int i = 0; i < n; i++){
        if (frq2[i] != frq[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n], frq[1025];
        memset(frq, 0, sizeof(frq));
        for (int i = 0; i < n; i++){
            cin >> a[i];
            frq[a[i]]++;
        }
        bool done = false;
        for (int i = 1; i < 1024; i++){
            if (solve(i, a, frq, n)){
                cout << i << '\n';
                done = true;
                break;
            }
        }
        if (!done) cout << "-1\n";
    }
}