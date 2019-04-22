#include <iostream>

using namespace std;

int main() {
    int n, s = 0, t = 0;
    string words;
    cin >> n;
    for (int i = 0; i < n; i++){
        getline(cin, words);
        getline(cin, words);
        for (int j = 0; j < words.length(); j++){
            if (words[j] == 's' || words[j] == 'S'){
                s++;
            }
            else if (words[j] == 't' || words[j] == 'T'){
                t++;
            }
        }
    }

    if (t > s){
        cout << "English\n";
    }
    else {
        cout << "French\n";
    }
}