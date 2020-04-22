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

int a[1000005], b[1000005];

int s(int l, int r, int v){
    while (l < r){
        int m = (l+r)/2;
        if (b[m] >= v){
            r = m;
        }
        else l = m+1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, len = 1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    b[1] = a[0];
    for (int i = 0; i < n; i++){
        if (a[i] <= b[1]){
            b[1] = a[i];
        }
        else if (a[i] > b[len]){
            len++;
            b[len] = a[i];
        }
        else{
            b[s(0, len, a[i])] = a[i];
        }
    }
    cout << len;
}
