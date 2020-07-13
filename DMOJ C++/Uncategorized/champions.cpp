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

const int MM = 1e5+5;
int a[MM], cnt[MM];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi v;
    for (int i = 0, x; i < n; i++){
        cin >> x;
        a[i] = x;
        v.pb(x);
    }
    srt(v);
    for (int i = 0; i < n; i++){
        auto it = upper_bound(v.begin(), v.end(), a[i]-1);
        cnt[i] = it - v.begin();
    }
    for (int i = 0, A, B; i < k; i++){
        cin >> A >> B;
        A--, B--;
        if (a[A] > a[B]){
            cnt[A]--;
        }
        else if (a[A] < a[B]){
            cnt[B]--;
        }
    }
    for (int i = 0; i < n; i++) cout << cnt[i] << ' ';
}