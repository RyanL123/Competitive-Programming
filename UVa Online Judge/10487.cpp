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
    int n = -1, m, count = 1;
    while (cin >> n && n != 0){
        for (int i = 0; i <= 1000; i++){
            A[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        cin >> m;
        cout << "Case " << count << ":\n";
        while (m--){
            int q;
            cin >> q;
            int closest = inf;
            int sum = 0;
            for (int i = 0; i < n; i++){
                for (int j = i+1; j < n; j++){
                    if (abs(q-(A[i]+A[j])) < closest){
                        closest = abs(q-(A[i]+A[j]));
                        sum = A[i]+A[j];
                    }
                }
            }
            cout << "Closest sum to " << q << " is " << sum << ".\n";
        }
        count++;
    }
}