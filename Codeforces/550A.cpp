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
bool AB[MM], BA[MM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n-1; i++){
        if (s.substr(i, 2) == "AB") AB[i] = true;
        if (s.substr(i, 2) == "BA") BA[i] = true;
    }
    int A = -1, B = -1, A2 = -1, B2 = -1;
    for (int i = 0; i < n-1; i++){
        if (AB[i] && A == -1) A = i;
        if (BA[i] && B2 == -1) B2 = i;
    }
    for (int i = n-2; i >= 0; i--){
        if (BA[i] && B == -1) B = i;
        if (AB[i] && A2 == -1) A2 = i;
    }
    if (A == -1 || B == -1) cout << "NO\n";
    else {
        if (A > B) swap(A, B);
        if (A2 > B2) swap(A2, B2);
        cout << (A+1<B||A2+1<B2?"YES":"NO") << '\n';
    }
}