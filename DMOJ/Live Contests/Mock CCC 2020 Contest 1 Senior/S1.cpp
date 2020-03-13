#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int larry[n];
    int other[n];
    int war = 0;
    for (int i = 0; i < n; i++){
        cin >> larry[i];
    }
    for (int i = 0; i < n; i++){
        cin >> other[i];
    }
    bool inWar = false;
    for (int i = 0; i < n; i++){
        if (inWar && larry[i] != other[i]){
            war++;
            inWar = false;
        }
        else if (larry[i] == other[i]){
            inWar = true;
            continue;
        }
    }
    if (inWar){
        cout << war+1 << endl;
    }
    else {
        cout << war << endl;
    }
}