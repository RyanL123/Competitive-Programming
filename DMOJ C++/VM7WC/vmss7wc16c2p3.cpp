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

int A[1000005], B[1000005], C[1000005], ind[1000005];

int s(int l, int r, int v){
    while (l < r){
        int m = (l+r)/2;
        if (ind[m] >= v) r = m;
        else l = m+1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a;
    for (int i = 1; i <= a; i++){
        int x;
        cin >> x;
        A[x] = i;
    }
    cin >> b;
    for (int i = 1; i <= b; i++){
        cin >> B[i];
        C[i] = A[B[i]];
    }
    int len = 1;
    for (int i = 1; i <= b; i++){
        if (C[i] != 0){
            ind[1] = C[i];
            break;
        }
    }
    if (ind[1] == 0){
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= b; i++){
        if (C[i] <= ind[1] && C[i] != 0){
            ind[1] = C[i];
        }
        else if (C[i] > ind[len]){
            len++;
            ind[len] = C[i];
        }
        else{
            ind[s(0, len, C[i])] = C[i];
        }
    }
    cout << len;
}
