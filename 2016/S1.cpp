#include <iostream>
#include <string>

using namespace std;

int main(){
    string word1, word2;
    int ast = 0, diff = 0;

    bool anagram = true;

    getline(cin, word1);
    getline(cin, word2);

    int word1Count[26] = {0};

    int word2Count[26] = {0};

    for (int i = 0; i < word1.length(); i++){
        if (isalpha(word1[i])){
            word1Count[int(word1[i]-97)]+=1;
        }
    }

    for (int i = 0; i < word2.length(); i++){
        if (word2[i] == '*'){
            ast++;
        }
        else if (isalpha(word2[i])){
            word2Count[int(word2[i]-97)]+=1;
        }
    }

    for (int i = 0; i < 26; i++){
        if (word1Count[i] != word2Count[i]){
            anagram = false;
            diff += abs(word1Count[i] - word2Count[i]);
        }
    }

    if (diff == ast){
        anagram = true;
    }

    if (anagram){
        cout << "A" << endl;
    }
    else{
        cout << "N" << endl;
    }
}

