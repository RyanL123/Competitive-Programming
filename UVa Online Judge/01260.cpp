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

int A[1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, b = 0;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++){
                if (A[j] <= A[i]) b++;
            }
        }
        cout << b << "\n";
    }
}