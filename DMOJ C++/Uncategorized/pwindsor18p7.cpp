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

bool cmp(string a, string b){
    return a+b > b+a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.pb(s);
    }
    sort(all(v), cmp);
    string s;
    for (string i : v) {
        cout << i;
    }
}