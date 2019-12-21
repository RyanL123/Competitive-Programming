#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, length;
    string word, sub;
    scanf("%i", &n);
    vector<pair<int, string>> words;

    for (int i = 0; i < n; i++){
        string temp;
        int len;
        cin >> temp;
        len = temp.length();
        words.push_back(make_pair(len, temp));
    }
    cin >> word;
    length = word.length();
    sort(words.begin(), words.end());

    //1 replacement
    if (words.size() == 1){
        if (words[0].first <= length){
            cout << words[0].second;
        }
        return 0;
    }
    for (int i = 0; i < n; i++){
        if (words[i].first > length){
            cout << words[i-1].second;
            break;
        }
        if (i == n-1){
            cout << words[i].second;
            break;
        }
    }
}