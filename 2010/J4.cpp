#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){

    int n, x;

    while (true){

        scanf("%i", &n);

        //checks for exit for sequence with length of 1
        if (n == 0){
            break;
        }
        else if (n == 1){
            printf("0\n");
            break;
        }

        //stores temperature pattern
        int temp[n];

        //gets temperatures
        for (int i = 0; i < n; i++){
            scanf("%i",&x);
            temp[i] = x;
        }

        //gets difference between every term
        vector<int>sequence;

        for (int i = 0; i < n; i++){
            if (i != n-1){
                sequence.push_back(temp[i+1]-temp[i]);
            }
        }


        //finds shortest pattern
        int diff = 0;

        //finds the shortest difference
        for (int i = 0; i < sequence.size(); i++){
            for (int j = i+1; j < sequence.size(); j++){
                if (sequence[i] == sequence[j]){
                    diff = j-i;
                    break;
                }
            }

            //verifies that it is a sequence
            for (int j = i+1; j < diff; j++){
                if (sequence[j] != sequence[j+diff]){
                    break;
                }
            }
        }

        if (diff == 0){
            diff = sequence.size();
        }

        printf("%i\n", diff);
    }
}
