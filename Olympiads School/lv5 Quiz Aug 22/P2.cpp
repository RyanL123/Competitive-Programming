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

const int MM = 2e6+5;
int a[MM], down = 1, up = 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 1; i < N; i++) {
        if (a[i]-a[i-1] > 0) up = max(up, down+1);
        else if (a[i]-a[i-1] < 0) down = max(down, up+1);
    }
    cout << max(up, down) << '\n';
}