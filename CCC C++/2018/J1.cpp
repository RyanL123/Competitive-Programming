#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int digitOne;
    int digitTwo;
    int digitThree;
    int digitFour;

    scanf("%d", &digitOne);
    scanf("%d", &digitTwo);
    scanf("%d", &digitThree);
    scanf("%d", &digitFour);

    if (digitOne == 8 || digitOne == 9){
        if (digitFour == 8 || digitFour == 9){
            if (digitTwo == digitThree){
                printf("ignore");
            }
            else{
                printf("answer");
            }
        }
        else{
            printf("answer");
        }
    }
    else{
        printf("answer");
    }

}
