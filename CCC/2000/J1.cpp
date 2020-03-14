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
    int d, days;
    cin >> d >> days;
    cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
    for (int i = 0; i < d-1; i++){
        cout << "    ";
    }
    int start = d;
    for (int i = 1; i <= days; i++){
        if (i >= 10) {
            cout << " " << i;
        }
        else {
            cout << "  " << i;
        }
        start++;
        if ((start-1)%7==0) cout << endl;
        else if (i != days) cout << " ";
    }
    if ((start-1)%7!=0) cout << endl;
}