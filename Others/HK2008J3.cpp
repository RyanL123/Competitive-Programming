#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, d, number;
    string name;
    vector<string> names;
    vector<int> numbers;

    cin >> n;

    int callCounter[n];

    //initializes all values in callCounter to 0
    for (int i = 0; i < n; i++){
        callCounter[i] = 0;
    }

    //gets input
    for (int i = 0; i < n; i++){
        //gets the name of the contact
        cin >> name;
        names.push_back(name);

        //gets the number of the contact
        cin >> number;
        numbers.push_back(number);

    }

    cin >> d;

    //counts the amount of time each number is called and stores it in the callCounter array
    for (int i = 0; i < d; i++){
        cin >> number;
        for (int j = 0; j < n; j++){
            if (number == numbers[j]){
                callCounter[j]++;
            }
        }
    }

    //finds the most called number and stores the index of that number
    int largest = 0, largestIndex = 0;
    for (int i = 0; i < n; i++){
      if (callCounter[i] > largest){
          largest = callCounter[i];
          largestIndex = i;
      }
      else if(callCounter[i] == largest){
          if (numbers[i] > numbers[largestIndex]){
              largestIndex = i;
          }
      }
    }

    cout << names[largestIndex] << endl;
}

