#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dp[5300];
int main() {
    int distance, c, clubs[110];
    cin >> distance >> c;
    //Get clubs input
    for (int i = 0; i < c; i++){
        cin >> clubs[i];
    }
    for (int i = 0; i < 5300; i++){
        dp[i] = INT_MAX;
    }

    //Total distance is 0
    dp[0] = 0;
    sort(clubs, clubs+c);

    //Bottom up DP
    for (int i = 1; i <= distance; i++){
        for (int j = 1; j <= c; j++){
            //Club's distance is less than total distance
            if (clubs[j-1] <= i){
                //Amount of swings using the club
                int subDistance = dp[i-clubs[j-1]]+1;
                //Prevent integer overflow
                if (subDistance != INT_MAX){
                    //Only use the club if the # of strokes is less than what is
                    //currently possible
                    dp[i] = min(subDistance, dp[i]);
                }
            }
        }
    }
    if (dp[distance] == INT_MAX){
        cout << "Roberta acknowledges defeat.";
    }
    else {
        printf("Roberta wins in %i strokes.", dp[distance]);
    }
}
