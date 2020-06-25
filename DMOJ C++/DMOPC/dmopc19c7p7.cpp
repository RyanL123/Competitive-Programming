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

struct fluid{
    ll v, c;
};

ll n, q, w;

bool f(fluid i, fluid j){
    ll cur = j.v * j.c + (i.v + j.v) * i.c;
    ll swp = i.v * i.c + (j.v + i.v) * j.c;
    return (swp-cur) >= w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<fluid> jar;
    cin >> n >> q >> w;
    for (int i = 0; i < n; i++){
        ll v, c;
        cin >> v >> c;
        jar.pb({v, c});
        for (int j = i; j >= 1; j--){
            int cur = j;
            while (cur >= 1 && f(jar[cur], jar[cur-1])){
                swap(jar[cur], jar[cur-1]);
                cur--;
            }
        }
    }
    for (int i = 0; i < q; i++){
        string s;
        cin >> s;
        if (s == "INSERT"){
            ll v, c;
            cin >> v >> c;
            jar.pb({v, c});
            for (int j = jar.size()-1; j >= 1; j--){
                int cur = j;
                while (cur >= 1 && f(jar[cur], jar[cur-1])){
                    swap(jar[cur], jar[cur-1]);
                    cur--;
                }
            }
        }
        else {
            int k;
            cin >> k;
            cout << jar[k-1].v << " " << jar[k-1].c << '\n';
        }
    }
}