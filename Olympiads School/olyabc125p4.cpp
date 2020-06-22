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
#define inf 0x3f3f3f3f

int a[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum = 0;
    int cnt = 0, mn = inf;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
        sum += abs(x);
    }
    for (int i = 0; i < n-1; i++){
        if (a[i] < 0 && a[i+1] < 0){
            a[i] = abs(a[i]);
            a[i+1] = abs(a[i+1]);
        }
    }
    for (int i = 0; i < n; i++){
        if (a[i] < 0){
            cnt++;
        }
    }
    if (cnt%2==0){
        cout << sum << '\n';
    }
    else {
        for (int i = 0; i < n; i++){
            mn = min(abs(a[i]), mn);
        }
        cout << sum - 2*mn << '\n';
    }
}