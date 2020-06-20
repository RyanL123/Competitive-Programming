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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        if (n==1) cout << "FastestFinger\n";
        else if (n%2==1 || n==2) cout << "Ashishgup\n";
        else {
            int x = 0;
            while (n%2==0){
                n/=2;
                x++;
            }
            if (n==1) cout << "FastestFinger\n";
            else if (x>=2) cout << "Ashishgup\n";
            else {
                bool prime = true;
                for (int i = 2; i <= ceil(sqrt(n)); i++){
                    if (n%i==0) prime = false;
                }
                if (prime) cout << "FastestFinger\n";
                else cout << "Ashishgup\n";
            }
        }
    }
}