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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 5; i++){
        int n, cnt = 0;
        cin >> n;
        int m = n;
        for (int i = 2; i <= 32; i++){
            while (n != 1 && m > i && n%i==0){
                n/=i;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}