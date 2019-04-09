#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>

using namespace std;

int main(){
    string key;
    string plainText;

    int i = 0;

    getline(cin, key);

    getline(cin, plainText);

    for (int j = 0; j < plainText.length(); j++){

        if (isalpha(plainText[j])){

            if (isupper(key[i])){

                if (isupper(plainText[j])){

                    cout << char((((plainText[j] - 65) + (key[i] - 65)) % 26) + 65);

                    if (i == key.length() - 1){
                        i = 0;
                    }
                    else{
                        i++;
                    }
                }
                else if (islower(plainText[j])){

                    cout << char((((plainText[j] - 97) + (key[i] - 65)) % 26) + 97);

                    if (i == key.length() - 1){
                        i = 0;
                    }
                    else{
                        i++;
                    }
                }
            }
            else if (islower(key[i])){

                if (isupper(plainText[j])){

                    cout << char((((plainText[j] - 65) + (key[i] - 97)) % 26) + 65);

                    if (i == key.length() - 1){
                        i = 0;
                    }
                    else{
                        i++;
                    }
                }
                else if (islower(plainText[j])){

                    cout << char((((plainText[j] - 97) + (key[i] - 97)) % 26) + 97);

                    if (i == key.length() - 1){
                        i = 0;
                    }
                    else{
                        i++;
                    }
                }
            }
        }
    }
}
