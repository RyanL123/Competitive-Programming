#include <iostream>
#include <vector>

using namespace std;

int main(){
    string city;
    int temperature, lowestIndex, lowest = 200;
    vector<string> cities{};
    vector<int> temp{};

    while (true){
        cin >> city;
        cin >> temperature;
        if (city == "Waterloo"){
            break;
        }
        else {
            cities.push_back(city);
            temp.push_back(temperature);
        }
    }

    for (int i = 0; i < temp.size(); i++){
        if (temp[i] < lowest){
            lowestIndex = i;
            lowest = temp[i];
        }
    }

    cout << cities[lowestIndex] << endl;

}
