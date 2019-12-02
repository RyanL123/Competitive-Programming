#include <iostream>

using namespace std;

int input[100010];
int inputNegative[100010];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        if (num >= 0){
            input[num]++;
        }
        else {
            inputNegative[-num]++;
        }
    }
    int largest = 0;
    for (int i = 0; i < 100010; i++){
        if (input[i] > largest){
            largest = input[i];
        }
        if (inputNegative[i] > largest){
            largest = inputNegative[i];
        }
    }
    for (int i = 100009; i > 0; i--){
        if (inputNegative[i] == largest){
            cout << -i << " ";
        }
    }
    for (int i = 0; i < 100010; i++){
        if (input[i] == largest){
            cout << i << " ";
        }
    }
}