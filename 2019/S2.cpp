#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

//checks if integer is prime
bool isPrime(int a){
  for (int b = 2; b < ceil(sqrt(a))+1; b++){
    if (a%b == 0){
      return false;
    }
  }
  return true;
}

int main() {
  //takes input
  int t,input;
  scanf("%i", &t);

  //finds average of primes
  for (int k = 0; k < t; k++){
    scanf("%i", &input);

    int a, b;
    for (int i = 2; i < 2*input; i++){
      a = i;
      b = 2*input-i;
      if (isPrime(a) && isPrime(b) && (a+b) == 2*input){
        printf("%i %i\n", a , b);
        break;
      }
    }
  }
} 
