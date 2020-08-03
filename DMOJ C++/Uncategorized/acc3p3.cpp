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

const int MM = 1e5+5;
string a[MM];
int pos[2][MM], pre = 0, cur = 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    deque<char> ans;
    for (char c = 'z'; c >= 'a'; c--) {
        while (true) {
            bool can = true;
            for (int i = 0; i < N; i++) {
                auto p = a[i].find(c, pos[cur][i]);
                if (p != string::npos) pos[pre][i] = p+1;
                else can = false;
            }
            if (!can) {
                for (int i = 0; i < N; i++) pos[pre][i] = pos[cur][i];
                break;
            }
            ans.pb(c);
            swap(pre, cur);
        }
    }
    if (ans.empty()) cout << "-1\n";
    else {
        for (char c : ans) cout << c;
        cout << '\n';
    }
}