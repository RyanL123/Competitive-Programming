#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string a;
    getline(cin, a);
    for (int i = 0; i < n; i++){
        vector<string> poem;
        for (int j = 0; j < 4; j++){
            string s;
            getline(cin, s);
            poem.push_back(s);
        }
        string word1;
        string word2;
        string word3;
        string word4;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (int j = poem[0].length()-1; j >= 0; j--){
            if (poem[0][j] == ' '){
                break;
            }
            else if (find(vowels.begin(), vowels.end(), tolower(poem[0][j])) != vowels.end()){
                word1+= tolower(poem[0][j]);
                break;
            }
            word1 += tolower(poem[0][j]);
        }
        reverse(word1.begin(), word1.end());

        for (int j = poem[1].length()-1; j >= 0; j--){
            if (poem[1][j] == ' '){
                break;
            }
            else if (find(vowels.begin(), vowels.end(), tolower(poem[1][j])) != vowels.end()){
                word2+= tolower(poem[1][j]);
                break;
            }
            word2 += tolower(poem[1][j]);
        }
        reverse(word2.begin(), word2.end());

        for (int j = poem[2].length()-1; j >= 0; j--){
            if (poem[2][j] == ' '){
                break;
            }
            else if (find(vowels.begin(), vowels.end(), tolower(poem[2][j])) != vowels.end()){
                word3+= tolower(poem[2][j]);
                break;
            }
            word3 += tolower(poem[2][j]);
        }
        reverse(word3.begin(), word3.end());

        for (int j = poem[3].length()-1; j >= 0; j--){
            if (poem[3][j] == ' '){
                break;
            }
            else if (find(vowels.begin(), vowels.end(), tolower(poem[3][j])) != vowels.end()){
                word4+= tolower(poem[3][j]);
                break;
            }
            word4 += tolower(poem[3][j]);
        }
        reverse(word4.begin(), word4.end());
        if (word1 == word2 &&
            word1 == word3 &&
            word1 == word4){
            cout << "perfect" << endl;
        }
        else if (word1 == word2 && word3 == word4){
            cout << "even" << endl;
        }
        else if (word1 == word3 && word2 == word4){
            cout << "cross" << endl;
        }
        else if (word1 == word4 && word2 == word3){
            cout << "shell" << endl;
        }
        else {
            cout << "free" << endl;
        }
    }
}
