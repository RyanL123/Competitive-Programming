#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    vector<int> vec;
    for (int i = 0; i < 4; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    cout << vec[0] << endl << vec[3] << endl;
}