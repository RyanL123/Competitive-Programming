#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> planks;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        planks.push_back(a);
    }
    sort(planks.begin(), planks.end());
    long long totalArea = 0;
    int low = 0, hi = n-1;
    while (abs(low-hi) > 1){
        if (abs(planks[low] - planks[low+1]) <= 1){
            if (abs(planks[hi] - planks[hi-1]) <= 1){
                totalArea += min(planks[low], planks[low+1])*min(planks[hi], planks[hi-1]);
                low+=2;
                hi-=2;
            }
            else {
                hi--;
            }
        }
        else {
            low++;
        }
    }
    cout << totalArea;
}