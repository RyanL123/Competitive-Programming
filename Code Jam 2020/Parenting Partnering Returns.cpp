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
#define inf 0x3f3f3f3f

struct task{
    int a, b, id;
};

bool cmp(task x, task y){
    return x.a < y.a;
}

void solve(vector<task> tasks){
    sort(tasks.begin(), tasks.end(), cmp);
    pii c = {0, 0}, j = {0, 0};
    char s[1005];
    for (task t : tasks){
        int a = t.a, b = t.b;
        if (a >= c.second){
            c = {a, b};
            s[t.id] = 'C';
        }
        else if (a >= j.second){
            j = {a, b};
            s[t.id] = 'J';
        }
        else {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    for (int i = 0; i < tasks.size(); i++){
        cout << s[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        int n;
        cin >> n;
        vector<task> tasks;
        for (int j = 0; j < n; j++){
            int a, b;
            cin >> a >> b;
            tasks.pb({a, b, j});
        }
        cout << "Case #" << i << ": ";
        solve(tasks);
        cout << "\n";
    }
}