#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

int main() {
    for (int i = 0; i < 5; i++){
        int a;
        cin >> a;
        int closest = INT_MAX;
        int closestJ = 0;
        for (int j = 0; j < a; j++){
            if (abs(pow(2, j)-a) < closest){
                closest = abs(pow(2, j)-a);
                closestJ = j;
            }
            else if (abs(pow(2, j)-a) == closest){
                if (pow(2, j) > pow(2, closestJ)){
                    closestJ = j;
                }
            }
        }
        cout << pow(2, closestJ) << endl;
    }
}
