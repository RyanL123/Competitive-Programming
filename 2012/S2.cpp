#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int total = 0;
    vector<int> roman;
    vector<int> arabic;
    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++){
        if (i % 2 == 0){
            arabic.push_back(input[i]-48);
        }
        else {
            if (input[i] == 'I'){
                roman.push_back(1);
            }
            else if (input[i] == 'V'){
                roman.push_back(5);
            }
            else if (input[i] == 'X'){
                roman.push_back(10);
            }
            else if (input[i] == 'L'){
                roman.push_back(50);
            }
            else if (input[i] == 'C'){
                roman.push_back(100);
            }
            else if (input[i] == 'D'){
                roman.push_back(500);
            }
            else {
                roman.push_back(1000);
            }
        }
    }

    for (int i = 0; i < roman.size(); i++){
        if (i < roman.size()-1){
            if (roman[i+1] > roman[i]){
                total-=roman[i]*arabic[i];
            }
            else{
                total+=roman[i]*arabic[i];
            }
        }
        else{
            total+=roman[i]*arabic[i];
        }
    }
    printf("%d", total);
}