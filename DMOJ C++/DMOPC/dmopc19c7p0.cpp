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
    ld a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << setprecision(8) << (a+b)/2 << '\n';
    cout << setprecision(8) << (a+c)/2 << '\n';
    cout << setprecision(8) << (a+d)/2 << '\n';
    cout << setprecision(8) << (b+c)/2 << '\n';
    cout << setprecision(8) << (b+d)/2 << '\n';
    cout << setprecision(8) << (c+d)/2 << '\n';
    cout << setprecision(8) << (a+b+c)/3 << '\n';
    cout << setprecision(8) << (a+b+d)/3 << '\n';
    cout << setprecision(8) << (a+c+d)/3 << '\n';
    cout << setprecision(8) << (b+c+d)/3 << '\n';
    cout << setprecision(8) << (a+b+c+d)/4 << '\n';
}