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

const int MM = 5005, MN = 2e5+5;
int a[MM];
bool prime[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ind = 0, mx = 0;
    cin >> n;
    memset(prime, true, sizeof(prime));
    for (int i = 2; i*i < MN; i++){
        if (prime[i]){
            for (int j = i*i; j < MN; j+=i){
                prime[j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cin >> a[i];
        for (int j = ceil(sqrt(a[i])); j >= 1; j--){
            if (a[i]%j==0){
                if (prime[j] && j > mx) {
                    ind = i, mx = j;
                }
                if (prime[a[i]/j] && a[i]/j > mx){
                    ind = i, mx = a[i]/j;
                }
            }
        }
    }
    cout << a[ind] << '\n';
}