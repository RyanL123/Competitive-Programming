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
    unsigned long long totalArea = 0;
    int low = n-3, hi = n-1;
    while (low >= 1 && planks.size() >= 4){
        if (abs(planks[hi]-planks[hi-1]) <= 1){
            if (abs(planks[low]-planks[low-1]) <= 1){
                unsigned long long area = min(planks[low], planks[low-1])*min(planks[hi], planks[hi-1]);
                if (area > totalArea){
                    totalArea = area;
                }
                planks.erase(planks.begin()+hi);
                planks.erase(planks.begin()+hi-1);
                planks.erase(planks.begin()+low);
                planks.erase(planks.begin()+low-1);
                hi = planks.size()-1;
                low = planks.size()-3;
            }
            else {
                low--;
            }
        }
        else {
            hi--;
            low--;
        }
    }
    cout << totalArea;
}