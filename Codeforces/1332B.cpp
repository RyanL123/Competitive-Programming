#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define inf 0x3f3f3f3f

bool prime[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    memset(prime, true, sizeof(prime));
    for (int i = 2; i*i < 100; i++){
        if (prime[i]){
            for (int j = i*i; j < 100; j+=i) prime[j] = false;
        }
    }
    while (t--){
        int n;
        cin >> n;
        int a[n], c[n];
        map<int, int> m;
        int cur = 1;
        for (int i = 0; i < n; i++){
            cin >> a[i];    
            for (int j = 2; j <= ceil(sqrt(a[i])); j++){
                if (a[i]%j==0 && prime[j]){
                    if (m[j] == 0){
                        m[j] = cur;
                        c[i] = cur;
                        cur++;
                    }
                    else c[i] = m[j];
                    break;
                }
            }
        }
        cout << cur-1 << '\n';
        for (int i = 0 ; i < n; i++) cout << c[i] << ' ';
        cout << '\n';
    }
}