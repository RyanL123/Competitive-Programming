#include <iostream>

using namespace std;

int main(){
    int n,m;
    int counter = 0;

    cin >> n >> m;

    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++){
            if (i+j == 10){
                counter++;
            }
        }
    }
    if (counter == 1){
        cout << "There is " << counter << " way to get the sum 10.";
    }
    else{
        cout << "There are " << counter << " ways to get the sum 10.";
    }
}
