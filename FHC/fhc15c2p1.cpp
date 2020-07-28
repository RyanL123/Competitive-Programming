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

void solve(int id) {
    int n;
    cin >> n;
    int a[n];
    deque<int> dq, dq2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dq.pb(a[i]);
    }
    bool flag = false;
    while (!dq.empty()) {
        if (dq2.empty()) {
            dq2.pb(dq.front());
            dq.pop_front();
        }
        else {
            if (dq.front() == dq2.front()-1) {
                dq2.push_front(dq.front());
                dq.pop_front();
            }
            else if (dq.front() == dq2.back()+1) {
                dq2.pb(dq.front());
                dq.pop_front();
            }
            else if (dq.back() == dq2.front()-1) {
                dq2.push_front(dq.back());
                dq.pop_back();
            }
            else if (dq.back() == dq2.back()+1) {
                dq2.pb(dq.back());
                dq.pop_back();
            }
            else break;
        }
    }
    flag |= dq.empty();
    dq.clear(), dq2.clear();
    for (int i = 0; i < n; i++) dq.pb(a[i]);
    while (!dq.empty()) {
        if (dq2.empty()) {
            dq2.pb(dq.back());
            dq.pop_back();
        }
        else {
            if (dq.front() == dq2.front()-1) {
                dq2.push_front(dq.front());
                dq.pop_front();
            }
            else if (dq.front() == dq2.back()+1) {
                dq2.pb(dq.front());
                dq.pop_front();
            }
            else if (dq.back() == dq2.front()-1) {
                dq2.push_front(dq.back());
                dq.pop_back();
            }
            else if (dq.back() == dq2.back()+1) {
                dq2.pb(dq.back());
                dq.pop_back();
            }
            else break;
        }
    }
    flag |= dq.empty();
    cout << "Case #" << id << ": " << (flag?"yes":"no") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}