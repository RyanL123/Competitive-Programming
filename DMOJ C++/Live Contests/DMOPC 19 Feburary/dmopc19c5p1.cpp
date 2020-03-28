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
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int count = 0;
    vector<string> items;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        items.pb(s);
    }
    for (int i = 0; i < m; i++){
        int t;
        cin >> t;
        bool flag = true;
        for (int j = 0; j < t; j++){
            string s;
            cin >> s;
            if (find(items.begin(), items.end(), s) == items.end()){
                flag = false;
            }
        }
        if (flag) count++;
    }
    cout << count;
}