#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long calculate(long n, long a, long b, long t){
    long total = n*a;
    if (total >= t){
        long diff = total - t;
        long q = floor(diff/(a+b));
        return n-q;
    }
    return -1;


}
int main() {
    int N, n, a, b, t;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> n >> a >> b >> t;
        cout << calculate(n, a, b, t) << endl;
    }
}