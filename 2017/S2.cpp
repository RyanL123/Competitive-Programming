#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    //initialize variables
    int n, input;
    scanf("%d", &n);
    int start = 0, end = n-1;
    int tides[110] {-1};

    //gets scrambled tides and sort them
    for (int i = 0; i < n; i++){
        scanf("%d", &input);
        tides[i] = input;
    }
    sort(tides, tides+n);


    vector<int> lowTide;
    vector<int> highTide;
    //gets half of vector size
    int half;
    if (n % 2 == 0){
        half = n/2;
    }
    else{
        half = n/2+1;
    }

    //split the sorted array into high tide and low tide, and reverse the low tide vector
    for (int i = 0; i < n; i++){
        if (i < half){
            lowTide.push_back(tides[i]);
        }
        else{
            highTide.push_back(tides[i]);
        }
    }
    reverse(lowTide.begin(), lowTide.end());

    //prints out low tide followed by high tide alternating
    for (int i = 0; i < half; i++){
        if (i < lowTide.size()){
            printf("%d ", lowTide[i]);
        }
        if (i < highTide.size()){
            printf("%d ", highTide[i]);
        }
    }
}