#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++){
        cout << num[i] << " ";
    }
}