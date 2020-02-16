#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int maxLuggage[300010];
int main() {
    vector<int> luggage;
    int n, k, height;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &height);
        luggage.push_back(height);
    }
    sort(luggage.begin(), luggage.begin()+n);
    for (int i = 0; i < n; i++){
        int highest = distance(luggage.begin(), upper_bound(luggage.begin()+i, luggage.end(), luggage[i]+k));
        maxLuggage[i] = highest - i;
    }
    int max = 0;
    for (int i = 0; i < n; i++){
        if (maxLuggage[i] > max){
            max = maxLuggage[i];
        }
    }
    printf("%d", max);
}