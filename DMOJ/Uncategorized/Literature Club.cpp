#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    int n, k, w;
    string input;
    int S = 0, N = 0, Y = 0, M = 0;
    cin >> n >> k >> w;

    vector <string> Sayori;
    vector <string> Natsuki;
    vector <string> Yuri;
    vector <string> Monika;

    for (int i = 0; i < w; i++){
        cin >> input;
        Sayori.push_back(input);
    }
    for (int i = 0; i < w; i++){
        cin >> input;
        Natsuki.push_back(input);
    }
    for (int i = 0; i < w; i++){
        cin >> input;
        Yuri.push_back(input);
    }
    for (int i = 0; i < w; i++){
        cin >> input;
        Monika.push_back(input);
    }

    //counts the closeness
    for (int i = 0; i < n*k; i++){
        cin >> input;
        for (int j = 0; j < w; j++){
            if (find(Sayori.begin(), Sayori.end(), input) != Sayori.end()){
                S++;
                Sayori.erase(find(Sayori.begin(), Sayori.end(), input));
            }
        }
        for (int j = 0; j < w; j++){
            if (find(Natsuki.begin(), Natsuki.end(), input) != Natsuki.end()){
                N++;
                Natsuki.erase(find(Natsuki.begin(), Natsuki.end(), input));
            }
        }
        for (int j = 0; j < w; j++){
            if (find(Yuri.begin(), Yuri.end(), input) != Yuri.end()){
                Y++;
                Yuri.erase(find(Yuri.begin(), Yuri.end(), input));
            }
        }
        for (int j = 0; j < w; j++){
            if (find(Monika.begin(), Monika.end(), input) != Monika.end()){
                M++;
                Monika.erase(find(Monika.begin(), Monika.end(), input));
            }
        }
    }

    //initializes arrays for sorting closeness
    int closeness[] {S,N,Y,M};
    vector<string> final {"Sayori","Natsuki","Yuri","Monika"};
    int highest = 0;

    //if the total closeness isn't 0
    if (S+N+Y+M != 0){

        //finds the highest closeness
        for (int i = 0; i < 4; i++){
            if (closeness[i] > highest){
                highest = closeness[i];
            }
        }

        //if the current person does not have the highest closeness, set it to NULL
        for (int i = 0; i < 4; i++){
            if (closeness[i] < highest){
                final[i] = "NULL";
            }
        }

        //print all the people without a status of NULL
        for (int i = 0; i < final.size(); i++){
            if (final[i] != "NULL"){
                cout << final[i] << endl;
            }
        }
    }

}