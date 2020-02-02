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
    int m;
    cin >> m;
    string combo;
    int point;
    cin >> combo >> point;
    int start = 0, score = s.length(), i = 1;
    if (s.length() == 1 && s == combo){
        cout << 1 + point;
        return 0;
    }
    else if (s.length() == 1){
        cout << 1;
        return 0;
    }
    while (start != s.length()){
        if (start+i > s.length()){
            i = 1;
            start++;
        }
        if (s.substr(start, i) == combo && combo.length() == i){
            start += i;
            score += point;
            i = 1;
        }
        else {
            i++;
        }
    }
    cout << score;
}
