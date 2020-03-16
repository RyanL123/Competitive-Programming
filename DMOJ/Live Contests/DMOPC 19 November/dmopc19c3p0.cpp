#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        bool arithmetic = true, geometric = true, zero = false;
        int arr[10];
        for (int j = 0; j < 10; j++) {
            int num;
            cin >> num;
            arr[j] = num;
        }
        for (int j = 0; j < 8; j++){
            if (arr[j] + arr[j+2] != 2*arr[j+1]){
                arithmetic = false;
            }
            if (arr[j]*arr[j+2] != arr[j+1]*arr[j+1]){
                geometric = false;
            }
        }
        if (geometric && arithmetic){
            cout << "both" << endl;
        }
        else if (geometric){
            cout << "geometric" << endl;
        }
        else if (arithmetic) {
            cout << "arithmetic" << endl;
        }
        else {
            cout << "neither" << endl;
        }
    }
}