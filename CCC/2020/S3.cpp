#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

int charCount[27];
int charCountH[27];
vector<string> used;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string n, h;
    cin >> n >> h;
    int substrs = 0;
    for (int i = 0; i < n.length(); i++){
        charCount[n[i]-97]++;
    }
    int i = 0, j = n.length()-1;
    while (j < h.length()){
        for (int a = 0; a < 27; a++){
            charCountH[a] = 0;
        }
        for (int a = i; a <= j; a++){
            charCountH[h[a]-97]++;
        }
        bool sub = true;
        for (int a = 0; a < 27; a++){
            if (charCount[a] != charCountH[a]){
                sub = false;
                break;
            }
        }
        if (sub){
            if (find(used.begin(), used.end(), h.substr(i, abs(j-i+1))) == used.end()){
                substrs++;
                used.push_back(h.substr(i, n.length()));
            }
        }
        i++;
        j++;
    }
    cout << substrs << endl;
}
