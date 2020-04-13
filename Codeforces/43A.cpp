#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    map<string, int> m;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        m[s]++;
    }
    string winner;
    int score = 0;
    for (pair<string, int> p : m){
        if (p.second > score){
            winner = p.first;
            score = p.second;
        }
    }
    cout << winner;
}
