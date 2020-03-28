#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void copy(vector<string> &v, int index, char c){
    v.emplace_back(v[index-1] + c);
}

int query(vector<string> v, string s){
    int longestPrefix = 0;
    int smallestIndex = INT_MAX;
    for (int i = 0; i < v.size(); i++){
        int count = 0;
        for (int j = 0; j < v[i].length(); j++){
            if (j >= s.length()){
                break;
            }
            if (v[i][j] == s[j]){
                count++;
            }
            else {
                break;
            }
        }
        if (count == 0){
            continue;
        }
        if (count > longestPrefix){
            longestPrefix = count;
            smallestIndex = i;
        }
        else if (count == longestPrefix && i < smallestIndex){
            longestPrefix = count;
            smallestIndex = i;
        }
    }
    if (smallestIndex == INT_MAX){
        return -1;
    }
    return smallestIndex+1;
}

int main() {
    string s;
    int q;
    cin >> s >> q;
    vector<string> vec = {s};
    while (q--){
        char instruction;
        cin >> instruction;
        if (instruction == 'C'){
            int x;
            char a;
            cin >> x >> a;
            copy(vec, x, a);
        }
        else {
            string s_i;
            cin >> s_i;
            cout << query(vec, s_i) << endl;
        }
    }
}