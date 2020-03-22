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

int A[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    while (true){
        for (int i = 0; i < k; i++){
            cin >> A[i];
        }
        for (int a = 0; a < k; a++){
            for (int b = a+1; b < k; b++){
                for (int c = b+1; c < k; c++){
                    for (int d = c+1; d < k; d++){
                        for (int e = d+1; e < k; e++){
                            for (int f = e+1; f < k; f++){
                                cout << A[a] << " " << A[b] << " " << A[c] << " " << A[d] << " " << A[e] << " " << A[f] << "\n";
                            }
                        }
                    }
                }
            }
        }
        cin >> k;
        if (k) cout << "\n";
        else break;
    }
}