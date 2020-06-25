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
    pair<string, int> combos[m];
    for (int i = 0; i < m; i++){
        string c;
        int p;
        cin >> c >> p;
        combos[i] = make_pair(c, p);
    }
    int len = 0;
    int start = 0;
    int longest = 0;
    int longestIndex = -1;
    while (start <= s.length()){
        for (int i = 0; i < m; i++){
            if (s.substr(start, len) == combos[i].first && combos[i].first.length() > longest){
                longest = combos[i].first.length();
                longestIndex = i;
            }
        }
        if (start+len > s.length()){
            if (longestIndex != -1){
                finalScore += combos[longestIndex].second;
                start += longest;
                len = 0;
                longest = 0;
                longestIndex = -1;
            }
            else {
                start++;
                len = 0;
            }
        }
        else {
            len++;
        }
    }
    cout << finalScore;
}