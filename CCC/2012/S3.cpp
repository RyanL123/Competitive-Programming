#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int readingsCount[1010];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        readingsCount[x]++;
    }

    vector<int>mostFrequent;
    vector<int>secondMostFrequent;
    int highestFrequent = 0;
    int secondHighestFrequent = 0;

    //Determines the values of the top 2 most frequent readings
    for (int i = 0; i < 1010; i++){
        if (readingsCount[i] > highestFrequent){
            highestFrequent = readingsCount[i];
        }
        else if (readingsCount[i] > secondHighestFrequent){
            secondHighestFrequent = readingsCount[i];
        }
    }

    //Add the most frequent and second most frequent readings
    for (int i = 0; i < 1010; i++){
        if (readingsCount[i] == highestFrequent && readingsCount[i] != 0){
            mostFrequent.push_back(i);
        }
        else if (readingsCount[i] == secondHighestFrequent && readingsCount[i] != 0){
            secondMostFrequent.push_back(i);
        }
    }

    sort(mostFrequent.begin(), mostFrequent.end());
    sort(secondMostFrequent.begin(), secondMostFrequent.end());

    if (mostFrequent.size() == 1){
        int largestDiff = -1;
        for (int i = 0; i < secondMostFrequent.size(); i++){
            if (abs(mostFrequent[0] - secondMostFrequent[i]) > largestDiff) {
                largestDiff = abs(mostFrequent[0] - secondMostFrequent[i]);
            }
        }
        cout << largestDiff;
    }
    else {
        cout << abs(mostFrequent[0] - mostFrequent[mostFrequent.size()-1]);
    }
}
