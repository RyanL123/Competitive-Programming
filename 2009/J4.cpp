#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int w, sum = 7, linebreak = 0;
    cin >> w;

    string words[] {"TO", "CCC", "GOOD", "LUCK", "TODAY"};
    int len[] {2, 3, 4, 4, 5};

    string output = "WELCOME";
    for (int i = 0; i < 5; i++){
        //only add a word if a space can be put in front of it
        if (sum + len[i] + 1 <= w){
            sum += len[i] + 1;
            words[i] = '.' + words[i];
        }
        else{
            int remaining = w-sum;
            linebreak = i;
            int j = linebreak;
            while (remaining != 0){
                words[j] = '.' + words[j];
                remaining--;
                if (j){
                }
            }
        }
    }
}
