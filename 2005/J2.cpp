#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int a,b;
    int numbers = 0;
    vector<int>RSA;

    cin >> a >> b;

    for (int i = a; i < b+1; i++){
      int divisors = 2;
      for (int j = 2; j < i; j++){
        if (i%j==0){
          divisors++;
        }
      }
      if (divisors == 4){
        numbers++;
      }
    }
    cout << "The number of RSA numbers between " << a << " and " << b << " is " << numbers << endl;
}
