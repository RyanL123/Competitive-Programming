#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, x;

    while (true){

        cin >> n;

        if (n == 0){
            break;
        }

        //stores temperature pattern
        int temp[n];

        //gets temperatures
        for (int i = 0; i < n; i++){
            cin >> x;
            temp[i] = x;
        }

        //gets difference between every term
        vector<int>sequence {};

        for (int i = 0; i < n; i++){
            if (i != n-1){
                sequence.push_back(temp[i+1]-temp[i]);
            }
        }

        int longest = 0;

        for (int i = 0; i < sequence.size(); i++){
            for (int j = 0; j < sequence.size(); j++){

            }
        }
    }
}