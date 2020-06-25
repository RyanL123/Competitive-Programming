#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define inf 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d == (a+b+c+1)*4-2*a-4*b-6*c){
        cout << "C" << a+b+c+1 << "H" << d << '\n';
    }
    else cout << "invalid\n";
}