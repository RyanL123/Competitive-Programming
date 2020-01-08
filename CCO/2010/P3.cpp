#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int main() {
    map<char, char> m;
    int n;
    for (int i = 0; i < 26; i++){
        char c;
        cin >> c;
        m[i+65] = c;
    }
    cin >> n;
}