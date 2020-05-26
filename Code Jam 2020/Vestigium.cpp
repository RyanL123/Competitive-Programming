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
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++){
        int n;
        cin >> n;
        set<int> setCol[n];
        int mdg = 0, rowCnt = 0, colCnt = 0, totCol[n];
        memset(totCol, 0, sizeof(totCol));
        for (int i = 0; i < n; i++){
            set<int> s;
            int totRow = 0;
            for (int j = 0; j < n; j++){
                int x;
                cin >> x;
                if (i == j){
                    mdg += x;
                }
                totRow += x;
                s.insert(x);
                totCol[j] += x;
                setCol[j].insert(x);
            }
            if (totRow != (n*(n+1))/2 || s.size() != n){
                rowCnt++;
            }
        }
        for (int i = 0; i < n; i++){
            if (totCol[i] != (n*(n+1))/2 || setCol[i].size() != n){
                colCnt++;
            }
            setCol[i].clear();
        }
        printf("Case #%d: %d %d %d\n", k, mdg, rowCnt, colCnt);
    }
}
