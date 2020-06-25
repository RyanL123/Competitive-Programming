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

string solve(string S[], int m, int n){
    for (int i = 0; i < m; i++){
        char c = S[0][i];
        for (int j = 0; j < 26; j++){
            S[0][i] = 'a'+j;
            bool flag = true;
            for (int k = 0; k < n; k++){
                int cnt = 0;
                for (int l = 0; l < m; l++){
                    if (S[k][l] != S[0][l]) cnt++;
                }
                if (cnt > 1) flag = false;
            }
            if (flag) return S[0];
        }
        S[0][i] = c;
    }
    return "-1";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string S[n];
        for (int i = 0; i < n; i++){
            cin >> S[i];
        }
        cout << solve(S, m, n) << "\n";
    }
}
