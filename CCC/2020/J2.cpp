#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r, p;
    cin >> p >> n >> r;
    int total = 0;
    int days = 0;
    while (total <= p){
        total += n * pow(r, days);
        days++;
    }
    cout << days-1 << endl;
}

