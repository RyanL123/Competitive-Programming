#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int leftSide[1000010];
int rightSide[1000010];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        leftSide[i] = INT_MAX;
        rightSide[i]= INT_MAX;
    }
    int leftPtr = 0;
    while (leftPtr < n){
        if (s[leftPtr] == '1'){
            int count = 1;
            leftPtr++;
            while (leftPtr < n && s[leftPtr] != '1'){
                leftSide[leftPtr] = count;
                leftPtr++;
                count++;
            }
        }
        else leftPtr++;
    }
    int rightPtr = n-1;
    while (rightPtr >= 0){
        if (s[rightPtr] == '1'){
            int count = 1;
            rightPtr--;
            while (rightPtr >= 0 && s[rightPtr] != '1'){
                rightSide[rightPtr] = count;
                rightPtr--;
                count++;
            }
        }
        else rightPtr--;
    }
    long long total = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '0') total += min(leftSide[i], rightSide[i]);
    }
    cout << total << endl;
}