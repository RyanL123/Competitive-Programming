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
    int start = 0, i = 1; // i = len of substring
    bool noCombos = true;
    int score = 0;
    int minLength = 0;
    while (start != s.length()){
        if (start+i > s.length()){
            i = 1;
            start++;
        }
        for (int k = start; k < s.length(); k++) {
            for (int j = 0; j < m; j++) {
                if (s.substr(start, i) == combos[j]) {
                    minLength = combos[j].length();
                    score = points[j];
                    noCombos = false;
                }
            }
            i++;
        }
    }
    cout << finalScore;
}