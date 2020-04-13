#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf INT_MAX

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++){
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> event;
        while (m--){
            int a;
            cin >> a;
            event.pb(a);
        }
        int shirts = n;
        int claimed = 0;
        int count = 0;
        for (int j = 1; j <= d; j++){
            if (shirts <= 0){
                count++;
                shirts = n + claimed;
            }
            if (find(event.begin(), event.end(), j) != event.end()){
                for (int k : event){
                    if (k == j){
                        claimed++;
                        shirts++;
                    }
                }
            }
            shirts--;
        }
        cout << count << '\n';
    }
}
