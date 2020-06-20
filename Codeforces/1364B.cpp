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

bool check(vi &a, int l){
    return abs(a[l] - a[l-1]) + abs(a[l+1] - a[l]) <= abs(a[l+1] - a[l-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vi a;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            a.pb(x);
        }
        int l = 1;
        while (l+1 < a.size()){
            if (check(a, l)){
                a.erase(a.begin()+l);
            }
            else l++;
        }
        cout << a.size() << '\n';
        for (int i = 0; i < a.size(); i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}