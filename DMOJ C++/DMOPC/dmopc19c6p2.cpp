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

int cnt[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    vi A;
    for (int i = 2; i <= ceil(sqrt(a)); i++){
        if (a % i == 0){
            A.pb(i);
        }
        while (a % i == 0){
            a /= i;
            cnt[i]++;
        }
    }
    if (a != 1){
        A.pb(a);
        cnt[a]++;
    }
    int n = inf;
    for (int i : A){
        int factCnt = 0;
        int target = i;
        while (b / target != 0){
            factCnt += b/target;
            target *= i;
        }
        int occurrences = factCnt / cnt[i];
        n = min(n, occurrences);
    }
    cout << n;
}