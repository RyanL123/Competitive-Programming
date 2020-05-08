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
const int MM = 1e4+5;
struct event{
    int x, lo, hi, v;
};
bool cmp(event a, event b){
    // Open edges before close edges in case x val is the same
    // This way rectangles touching on endpoints do not get added to the perimeter
    return a.x < b.x || (a.x == b.x && a.v > b.v);
}
int n, ans, cnt[MM*2];
vector<event> ex, ey;
void f(){
    sort(ex.begin(), ex.end(), cmp);
    // Only increase counter if the cnt at y value is increased from 0 to 1 or vise versa
    for (event e : ex){
        if (e.v > 0){
            for (int i = e.lo; i < e.hi; i++){
                if (++cnt[i] == 1) ans++;
            }
        }
        else {
            for (int i = e.lo; i < e.hi; i++){
                if (--cnt[i] == 0) ans++;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    // Generate event points
    for (int i = 1; i <= n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += MM; b += MM; c += MM; d += MM;
        ex.pb({a, b, d, 1});
        ex.pb({c, b, d, -1});
        ey.pb({b, a, c, 1});
        ey.pb({d, a, c, -1});
    }
    f();
    // Swap x and y coordinates and repeat the process
    swap(ex, ey);
    f();
    cout << ans << '\n';
}
