/*
ID: ryan.li2
TASK: gift1
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
    freopen("gift1.in", "r", stdin);
    int NP;
    map<string, int> m;
    vector<string> order;
    cin >> NP;
    for (int i = 0; i < NP; i++){
        string s;
        cin >> s;
        m[s] = 0;
        order.pb(s);
    }
    string s;
    while (cin >> s){
        int M, NG;
        cin >> M >> NG;
        m[s] -= M;
        for (int i = 0; i < NG; i++){
            string a;
            cin >> a;
            m[a] += M/NG;
        }
        if (NG != 0) m[s] += M%NG;
        else m[s] += M;
    }
    freopen("gift1.out", "w", stdout);
    for (string p: order){
        cout << p << " " << m[p] << "\n";
    }
}