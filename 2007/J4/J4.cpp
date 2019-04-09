#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main(){
    string word1, word2;

    bool anagram = true;

    getline(cin, word1);
    getline(cin, word2);

    int word1Count[26] = {0};

    int word2Count[26] = {0};

    for (int i = 0; i < word1.length(); i++){
        if (isalpha(word1[i])){
            word1Count[int(word1[i]-65)]+=1;
        }
    }

    for (int i = 0; i < word2.length(); i++){
        if (isalpha(word2[i])){
            word2Count[int(word2[i]-65)]+=1;
        }
    }

    for (int i = 0; i < 26; i++){
        if (word1Count[i] != word2Count[i]){
            anagram = false;
        }
    }

    if (anagram){
        cout << "Is an anagram." << endl;
    }
    else{
        cout << "Is not an anagram." << endl;
    }

}
