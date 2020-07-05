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

int h, k;
vi v;
int shorter(int a, int b){
    int x = abs(a-b);
    int y = min(a, b) + 1000000 - max(a, b);
    return min(x, y);
}
bool solve(int len){
    int cnt = 0, ptr = 1, prev = v[0];
    while (ptr < h){
        while (ptr < h && shorter(v[ptr], prev) <= len){
            ptr++;
        }
        cnt++;
        prev = v[ptr];
    }
    return cnt <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h;
    for (int i = 0, x; i < h; i++){
        cin >> x;
        v.pb(x);
    }
    srt(v);
    int mx = 0;
    for (int i = 0; i < h-1; i++){
        mx = max(mx, v[i+1]-v[i]);
    }
    // Shift max gap to begin/end
    while (abs(v[0] - v[h-1]) != mx){
        v.pb(v[0]);
        v.erase(v.begin());
    }
    cin >> k;
    if (k >= h) cout << "0\n";
    else {
        int l = 0, r = 1000000;
        while (l < r){
            int m = (l+r)/2;
            if (solve(m)) r = m;
            else l = m+1;
        }
        cout << ceil((double)r/2) << '\n';
    }
}