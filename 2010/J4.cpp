#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int n, x;

    while (true){
        again :
        scanf("%i", &n);

        if (n == 0){
            break;
        }

        //gets temperatures
        int temp[n];
        for (int i = 0; i < n; i++){
            scanf("%i", &x);
            temp[i] = x;
        }

        //sequence has length of 1
        if (n == 1){
            printf("0\n");
            goto again;
        }
        else if (n == 2){
            printf("1\n");
            goto again;
        }

        //stores difference between temps
        int difference [50] {0};

        for (int i = 0; i < n; i++){
            if (i != n-1){
                difference[i] = temp[i+1]-temp[i];
            }
        }

        //finds the shortest difference
        int length = 1;
        while (length != n){
            bool repeats = true;
            for (int i = 0; i < n-length-1; i++){
                if (difference[i] != difference[i+length]){
                    repeats = false;
                    break;
                }
            }
            if (repeats){
                break;
            }
            length++;
        }

        //if there are no repeating patterns the length is the entire pattern
        if (length == n){
           printf("%i\n", n-1);
        }
        else {
            printf("%i\n", length);
        }
    }
}
