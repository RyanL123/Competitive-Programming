#include <iostream>

using namespace std;

long long XOR(long long num){
    long long ans[4] = {num, 1, num+1, 0};
    return ans[num%4];
}

int main() {
    long long t, s, f;
    cin >> t;

    while (t--){
        cin >> s >> f;
        long long ans = XOR(s-1)^XOR(f);
        cout << ans << endl;
    }
}