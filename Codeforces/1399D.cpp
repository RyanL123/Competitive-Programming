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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        int pos[n+1], cnt = 0, id = 1;
        memset(pos, 0, sizeof(pos));
        deque<int> one, zero;
        for (int i = 0; i < n; i++) {
            if (one.empty() && zero.empty()) {
                if (s[i]=='0') {
                    zero.pb(id), pos[i] = id;
                }
                else {
                    one.pb(id), pos[i] = id;
                }
            }
            else {
                if (s[i]=='0') {
                    if (one.empty()) {
                        pos[i] = id+1;
                        zero.pb(id+1);
                        id++;
                    }
                    else {
                        pos[i] = one.front();
                        zero.pb(one.front());
                        one.pop_front();
                    }
                }
                else {
                    if (zero.empty()) {
                        pos[i] = id+1;
                        one.pb(id+1);
                        id++;
                    }
                    else {
                        pos[i] = zero.front();
                        one.pb(zero.front());
                        zero.pop_front();
                    }
                }
            }
        }
        cout << id << '\n';
        for (int i = 0; i < n; i++) cout << pos[i] << ' ';
        cout << '\n';
    }
}