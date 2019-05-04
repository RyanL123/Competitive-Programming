#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    vector<int> luggage;
    vector<int> diff;
    int n, k, height;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &height);
        luggage.push_back(height);
    }
    sort(luggage.begin(), luggage.begin()+n);

    for (int i = 0; i < luggage.size(); i++){
        if (i != luggage.size()-1){
            diff.push_back(luggage[i+1] - luggage[i]);
        }
    }
    int highest = 0;
    int index = 0;
    int maxRange = 0;
    for (int i = 0; i < diff.size(); i++){
        if (diff[i] > k || highest+diff[i] > k){
            highest = 0;
            if (i-index > maxRange){
                maxRange = i-index;
            }
            continue;
        }
        if (highest == 0){
            index = i;
        }
        highest += diff[i];
    }

    printf("%d", highest+1);

}