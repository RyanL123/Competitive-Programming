#include <iostream>

using namespace std;

int main(){
    int a,b,c,n;
    int counter = 0;
    cin >> a >> b >> c >> n;
    int total = a+b+c;

    for (int k = 0; k < total; k++){
        for (int j = 0; j < total; j++){
            for (int i = 0; i < total; i++){
                if (i == 0 && j == 0 && k == 0){

                }
                else{
                    if (i*a + j*b + k*c <= n){
                    cout << i << " Brown Trout, " << j << " Northern Pike, " << k << " Yellow Pickerel\n";
                    counter++;
                    }
                }
            }
        }
    }
    cout << "Number of ways to catch fish: " << counter;
}
