#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int w, currentLine = 0, currentWords = 0, previousI = 0;
    cin >> w;
    string words[] {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};
    int spaces[6] = {0};
    for (int i = 0; i < 6; i++){
        if (currentLine + currentWords + words[i].length() <= w){
            currentWords++;
            currentLine += words[i].length();
        }
        else{
            int spacesLeft = w - currentLine;
            int j = previousI;
            while (spacesLeft){
                if (j >= i-1){
                    j = previousI;
                }
                spaces[j]++;
                j++;
                spacesLeft--;
            }
            for (int a = previousI; a < i; a++){
                cout << words[a];
                for (int k = 0; k < spaces[a]; k++){
                    cout << ".";
                }
            }
            cout << "\n";
            previousI = i;
            currentLine = 0;
            currentWords = 0;
            i--;
        }
    }
    if (currentLine){
        int spacesLeft = w - currentLine;
        int j = previousI;
        while (spacesLeft){
            if (j >= 5){
                j = previousI;
            }
            spaces[j]++;
            j++;
            spacesLeft--;
        }
        for (int a = previousI; a < 6; a++){
            cout << words[a];
            for (int k = 0; k < spaces[a]; k++){
                cout << ".";
            }
        }
        cout << "\n";
    }
}
