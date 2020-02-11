#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total = 0;
    for (int i = 0; i < n; i++){
        if (s[0] == '0' && i == 0){
            int index = 0;
            for (int j = 0; j < n; j++){
                if (s[j] == '1'){
                    index = j;
                    break;
                }
            }
            for (int j = 0; j < index; j++){
                total += index-j;
            }
            i = index-1;
        }
        else {
            int index = -1;
            for (int j = i+1; j < n; j++){
                if (s[j] == '1'){
                    index = j;
                    break;
                }
            }
            if (index == -1){
                for (int j = i+1; j < n; j++){
                    total += j-i;
                }
                break;
            }
            else {
                // Even terms
                if (index-i == 1){
                    continue;
                }
                if ((index-i+1)%2 == 0){
                    int locTotal = 0;
                    for (int j = i+1; j < i+(index-i+1)/2; j++){
                        locTotal += j-i;
                    }
                    total += locTotal*2;
                }
                // Odd terms
                else {
                    int locTotal = 0;
                    for (int j = i+1; j <= floor((index-i+1)/2); j++){
                        locTotal += j-i;
                    }
                    total += locTotal;
                    total += floor((index-i+1)/2)+1-i;
                }
                i = index-1;
            }
        }
    }
    cout << total << endl;
}