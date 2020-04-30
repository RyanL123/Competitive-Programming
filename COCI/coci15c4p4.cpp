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

ull n, k, q;

ull lvl(ull x){
    ull level = 0, cnt = 0;
    while (cnt + pow(k, level) < x){
        cnt += pow(k, level);
        level++;
    }
    return level;
}

ull parent(ull x){
    return (x+k-2)/k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> q;
    while (q--){
        ull x, y;
        cin >> x >> y;
        if (lvl(x) == lvl(y) && parent(x) == parent(y)){
            cout << 2 << "\n";
        }
        else {
            if (lvl(x) < lvl(y)) swap(x, y);
            ull cnt = 0;
            while (lvl(y) != lvl(x)){
                x = parent(x);
                cnt++;
            }
            while (x != y){
                x = parent(x);
                y = parent(y);
                cnt += 2;
            }
            cout << cnt << "\n";
        }
    }
}
