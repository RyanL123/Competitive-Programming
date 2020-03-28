#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    string name;
    bool good = true;
    cin >> n;
    map<string, string>pair;
    string name1 [n];
    string name2 [n];

    //gets names and stores them in 2 different arrays
    for (int i = 0; i < n; i++){
       cin >> name;
       name1[i] = name;
    }
    for (int i = 0; i < n; i++){
        cin >> name;
        name2[i] = name;
    }

    //initializes hash map
    for (int i = 0; i < n; i++){
        pair[name1[i]] = name2[i];
    }

    for (int i = 0; i < n; i++){
        if (pair[name1[i]] == name1[i]){
            good = false;
            break;
        }
        else if (name1[i] != pair[pair[name1[i]]]){
            good = false;
            break;
        }
    }

    if (good){
        cout << "good";
    }
    else{
        cout << "bad";
    }

}