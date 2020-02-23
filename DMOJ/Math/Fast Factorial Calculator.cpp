#include <iostream>
#include <cmath>

using namespace std;

unsigned long long mod = pow(2, 32);

int main(){
    unsigned long long n, a;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        if (a > 33){
            cout << 0 << endl;
        }
        else {
            unsigned long long ans = 1;
            for (int j = 2; j <= a; j++){
                ans = (ans%mod * j%mod)%mod;
            }
            cout << ans << endl;
        }
    }
}