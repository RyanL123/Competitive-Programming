#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <map>

using namespace std;

int main() {
    int k;
    cin >> k;
    map<string, string> m;
    while (k--){
        string a, b;
        cin >> a >> b;
        m[b] = a;
    }
    string s;
    cin >> s;
    int start = 0;
    int len = 1;
    while (len < s.length()) {
        if (m[s.substr(start, len)] != "") {
            cout << m[s.substr(start, len)];
            start += len;
            len = 1;
        }
        else {
            len++;
        }
    }
}
