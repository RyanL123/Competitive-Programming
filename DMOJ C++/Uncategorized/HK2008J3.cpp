#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n, d, number;
    string name;
    vector<string> names;
    vector<int> numbers;

    scanf("%i", &n);

    //stores name and numbers in separate vectors with synced indices
    for (int i = 0; i < n; i++) {
        cin >> name >> number;
        names.push_back(name);
        numbers.push_back(number);
    }

    scanf("%i", &d);

    //initializes callCount array
    int callCount[n];
    for (int i = 0; i < n; i++){
        callCount[i] = 0;
    }

    //gets call history
    for (int i = 0; i < d; i++){
        scanf("%i", &number);
        for (int j = 0; j < n; j++){
            if (numbers[j] == number){
                callCount[j]++;
            }
        }
    }

    //finds the most called phone number
    int largest = -1, largestIndex = 0;
    for (int i = 0; i < n; i++){
        if (callCount[i] > largest){
            largest = callCount[i];
            largestIndex = i;
        }
        //tie breaker between numbers
        else if (callCount[i] == largest){
            if (numbers[i] < numbers[largestIndex]){
                largest = callCount[i];
                largestIndex = i;
            }
        }
    }

    cout << names[largestIndex] << endl;
}
