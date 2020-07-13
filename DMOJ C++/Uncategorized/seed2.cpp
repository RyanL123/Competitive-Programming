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

const int MM = 2e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll lo = 1, hi = MM;
    while (lo < hi){
        ll m = (lo+hi)/2;
        cout << m << endl;
        string s;
        cin >> s;
        if (s == "SINKS") lo = m+1;
        else if (s == "FLOATS") hi = m-1;
        else break;
    }
}