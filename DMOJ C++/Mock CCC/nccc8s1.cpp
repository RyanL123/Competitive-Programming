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
    string A, S;
    cin >> A >> S;
    set<string> ans;
    for (int i = 0; i < S.size(); i++) {
        string X, Y, Z;
        Y = S;
        for (int j = 0; j < A.size(); j++) {
            X = S;
            ans.insert(X.insert(i, 1, A[j]));
        }
        for (int j = 0; j < A.size(); j++) {
            X = S;
            ans.insert(X + A[j]);
        }
        ans.insert(Y.erase(i, 1));
        for (int j = 0; j < A.size(); j++) {
            Z = S;
            if (Z[i] == A[j]) continue;
            Z[i] = A[j];
            ans.insert(Z);
        }
    }
    for (string s : ans) cout << s << '\n';
}