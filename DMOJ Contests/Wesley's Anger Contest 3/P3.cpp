#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int m, finalScore = s.length();
    cin >> m;
    string combos[m];
    int points[m];
    for (int i = 0; i < m; i++){
        cin >> combos[i];
        cin >> points[i];
    }
    int end = 0;
    while (end < s.length()){
        bool comboFound = false;
        for (int i = s.length(); i >= end; i--){
            for (int j = 0; j < m; j++){
                if (s.substr(end, i) == combos[j]){
                    finalScore += points[j];
                    end = i+1;
                    comboFound = true;
                }
            }
        }
        if (!comboFound){
            end++;
        }
    }
    cout << finalScore;
}