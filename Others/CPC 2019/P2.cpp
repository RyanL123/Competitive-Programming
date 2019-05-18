#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    vector<int> luggage;
    int n, k, height;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &height);
        luggage.push_back(height);
    }
    sort(luggage.begin(), luggage.begin()+n);

    int i = 0, j = n-1, it = 1;

    while (i < j){
        if (luggage[j] - luggage[i] <= k){
            printf("%d", j-i+1);
            break;
        }
        if (it %2 == 0){
            j--;
            it++;
        }
        else{
            i++;
            it++;
        }
    }



}