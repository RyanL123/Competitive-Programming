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

const int MM = 105;
string names[MM];
int scores[MM];
struct person {
    int score;
    string name;
};
bool cmp(person a, person b) {
    return a.score < b.score;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    vector<person> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        names[i] = s;
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0, x; j < n; j++) {
            cin >> x;
            scores[j] += x;
        }
    }
    for (int i = 0; i < n; i++) v.pb(person{scores[i], names[i]});
    sort(all(v), cmp);
    vector<person> ans;
    for (int i = n-1; i >= 0; i--) {
        ans.pb(person{n-1-i+3, v[i].name});
    }
    sort(all(ans), cmp);
    for (person x : ans) {
        cout << x.score << ". " << x.name << '\n';
    }
}