#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

int main() {
    int n;
    double lowest = 1000000001.0;
    vector<double> villages;
    cin >> n;
    for (int i = 0; i < n; i++){
        double input;
        cin >> input;
        villages.push_back(input);
    }
    sort(villages.begin(), villages.end());
    for (int i = 1; i < n-1; i++){
        double size = (villages[i] - villages[i-1])/2 + (villages[i+1]- villages[i])/2;
        if (size < lowest){
            lowest = size;
        }
    }
    printf("%.1f", lowest);
}
