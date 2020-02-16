#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    bool diff = false;
    for (int i = 0; i < s1.length(); i++){
        if (s1[i] != s2[i] && diff){
            cout << "LARRY IS DEAD!";
            return 0;
        }
        else if (s1[i] != s2[i] && !diff){
            diff = true;
        }
    }
    if (diff){
        cout << "LARRY IS SAVED!";
    }
    else {
        cout << "LARRY IS DEAD!";
    }
}