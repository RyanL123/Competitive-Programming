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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int d;
        cin >> d;
        vector<pair<string, pii>> cars;
        while (d--){
            string m;
            int l, h;
            cin >> m >> l >> h;
            pair<string, pii> c = mp(m, mp(l, h));
            cars.pb(c);
        }
        int q;
        cin >> q;
        while (q--){
            int count = 0;
            int p;
            cin >> p;
            for (int i = 0; i < cars.size(); i++){
                if (p <= cars[i].second.second && p >= cars[i].second.first){
                    count++;
                }
            }
            if (count > 1 || count == 0) {
                cout << "UNDETERMINED\n";
            }
            else {
                for (int i = 0; i < cars.size(); i++){
                    if (p <= cars[i].second.second && p >= cars[i].second.first){
                        cout << cars[i].first << "\n";
                        count++;
                    }
                }
            }
        }
        if (t >= 1) cout << "\n";
    }
}