#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, input;
    vector<int> vec;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    cout << vec[n-1] - vec[0];
}