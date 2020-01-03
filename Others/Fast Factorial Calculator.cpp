#include <iostream>
#include <cmath>

using namespace std;

unsigned long long modulo = pow(2, 32);
unsigned long long fact(unsigned long long n){
    unsigned long long answer = 1;
    for (unsigned long long j = n; j > 0; j--){
        answer = (answer%modulo * j%modulo)%modulo;
        answer %= modulo;
    }
    return answer;
}

int main(){
    unsigned long long n, a;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        cout << fact(a) << endl;
    }
}