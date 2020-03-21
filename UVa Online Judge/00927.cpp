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

int eq[21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    cin >> c;
    while (c--){
        int a, d, k;
        for (int i = 0; i < 21; i++){
            eq[i] = 0;
        }
        cin >> a;
        for (int i = 0; i <= a; i++){
            cin >> eq[i];
        }
        cin >> d >> k;
        ll terms = 1;
        ll sum = (terms*(d+(terms)*d))/2;
        while (sum < k){
            terms++;
            sum = (terms*(d+(terms)*d))/2;
        }
        ll ans = 0;
        if (sum == k){
            for (int i = 0; i <= a; i++){
                ans += eq[i]*pow(terms, i);
            }
        }
        else {
            for (int i = 0; i <= a; i++){
                ans += eq[i]*pow(terms, i);
            }
        }
        cout << ans << endl;
    }
}