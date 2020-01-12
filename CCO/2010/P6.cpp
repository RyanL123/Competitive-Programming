#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int cycle(char original, char start, map<char, char> m, int count){
    if (m[start] == original){
        return count+1;
    }
    else {
        return cycle(original, m[start], m, count+1);
    }
}

int main() {
    map<char, char> m;
    string s;
    int n, cycleCount[27];
    for (int i = 0; i <= 26; i++){
        char c;
        cin >> c;
        if (i == 26){
            m['_'] = c;
        }
        else {
            m[i+65] = c;
        }
    }
    cin >> n;
    cin >> s;
    for (int i = 0; i < 27; i++){
        if (i == 26){
            cycleCount[i] = cycle('_', '_', m, 0);
        }
        else {
            cycleCount[i] = cycle((char)(i + 65), (char)(i + 65), m, 0);
        }
    }
    for (int j = 0; j < s.length(); j++){
        if (s[j] == '_') {
            if (cycleCount[26] != 0){
                int k = n % cycleCount[26];
                for (int i = 0; i < k; i++) {
                    s[j] = m[s[j]];
                }
            }
        }
        else {
            if (cycleCount[s[j] - 65] != 0) {
                int k = n % cycleCount[s[j] - 65];
                for (int i = 0; i < k; i++) {
                    s[j] = m[s[j]];
                }
            }
        }
    }
    cout << s;
}