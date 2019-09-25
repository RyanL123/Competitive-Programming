#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int r, l, max = 0;
    char input;

    cin >> r >> l;
    vector<string> lights;

    for (int i = 0; i < r; i++){
        string combination;
        for (int j = 0; j < l; j++){
            cin >> input;
            combination += input;
        }
        lights.push_back(combination);
    }

    vector<string> previousPossible;
    vector<string> possible;
    for (int i = r-1; i > 0; i--){
        previousPossible = possible;
        possible.clear();
        string below = lights[i];
        string output = below;
        //the button is not pressed
        previousPossible.push_back(below);
        //if the button is pressed for every combination of the row above
        for (int j = 0; j < previousPossible.size(); j++){
            for (int k = 0; k < r; k++){
                if (previousPossible[j][k] == below[k]){
                    output[k] = 0;
                }
                else {
                    output[k] = 1;
                }
            }
            possible.push_back(output);
        }
        max = possible.size();
    }
    cout << max+1;
}