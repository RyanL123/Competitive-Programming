#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int r, l, max = 0;
    char input;

    cin >> r >> l;
    vector<string> lights;

    //gets initial combination of lights
    for (int i = 0; i < r; i++){
        string combination;
        for (int j = 0; j < l; j++){
            cin >> input;
            combination += input;
        }
        lights.push_back(combination);
    }

    //Stores all possibilities of lights from the previous row
    vector<string> previousPossible;
    vector<string> possible = {lights[0]};
    for (int i = 1; i < r; i++){
        previousPossible = possible;
        possible.clear();
        string above = lights[i-1];
        string below = lights[i];
        string output = below;
        //if the button is pressed for every combination of the row above
        for (int j = 0; j < previousPossible.size(); j++){
            for (int k = 0; k < l; k++){
                if (previousPossible[j][k] == below[k]){
                    output[k] = '0';
                }
                else {
                    output[k] = '1';
                }
            }
            //only adds unique combinations
            //Button was pressed
            if (find(possible.begin(), possible.end(), output) == possible.end()) {
                possible.push_back(output);
            }
            // Button was not pressed
            if (find(possible.begin(), possible.end(), below) == possible.end()){
                possible.push_back(below);
            }
        }
        max = possible.size();
    }
    cout << max;
}