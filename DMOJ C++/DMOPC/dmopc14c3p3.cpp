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

struct person {
    string name;
    int skill, id;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<person> v;
    for (int i = 0; i < n; i++) {
        string s;
        int skill;
        cin >> s >> skill;
        v.pb({s, skill, i});
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, d;
        cin >> s >> d;
        string name;
        int skill = inf, id = -1;
        for (int j = 0; j < n; j++) {
            if (v[j].skill >= s && v[j].skill <= s+d) {
                if (skill > v[j].skill-s) {
                    skill = v[j].skill-s;
                    name = v[j].name;
                    id = v[j].id;
                }
                else if (skill == v[j].skill-s && v[j].id < id) {
                    skill = v[j].skill-s;
                    name = v[j].name;
                    id = v[j].id;
                }
            }
        }
        cout << (skill==inf?"No suitable teacher!":name) << '\n';
    }
}