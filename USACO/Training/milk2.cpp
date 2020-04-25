/*
ID: ryan.li2
TASK: milk2
LANG: C++
*/
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milk2.in", "r", stdin);
    int n, idle = 0, milk = 0;
    cin >> n;
    vii c;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        c.pb(mp(a,b));
    }
    srt(c);
    int a = c[0].first, b = c[0].second;
    for (int i = 1; i < n; i++){
        if (c[i].first > b){
            idle = max(idle, c[i].first - b);
            a = c[i].first, b = c[i].second;
        }
        else if (c[i].second > b){
            milk = max(milk, c[i].second - a);
            b = c[i].second;
        }
    }
    milk = max(milk, b-a);
    freopen("milk2.out", "w", stdout);
    cout << milk << " " << idle << "\n";
}
