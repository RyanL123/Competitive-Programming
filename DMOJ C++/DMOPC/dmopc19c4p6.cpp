#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned long long n, q;
    cin >> n >> q;
    unsigned long long arr[n+1];
    for (unsigned long long i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for (unsigned long long i = 0; i < q; i++){
        unsigned long long instruction;
        cin >> instruction;
        if (instruction == 1){
            unsigned long long x;
            cin >> x;
            cout << arr[x] << endl;
        }
        else if (instruction == 2){
            unsigned long long x, y, t;
            bool ignore = false;
            cin >> x >> y >> t;
            for (unsigned long long j = x; j <= y; j++){
                if (arr[j] < t){
                    ignore = true;
                    break;
                }
            }
            if (!ignore){
                for (unsigned long long j = x; j <= y; j++){
                    arr[j] -= t;
                }
            }
        }
        else if (instruction == 3){
            unsigned long long x, y, t;
            cin >> x >> y >> t;
            for (unsigned long long j = x; j <= y; j++){
                arr[j] = (t+j)-y;
            }
        }
        else if (instruction == 4){
            unsigned long long x, y;
            cin >> x >> y;
            for (unsigned long long j = x; j <= y; j++){
                double root = sqrt(arr[j]);
                arr[j] = floor(root);
            }
        }
    }
}