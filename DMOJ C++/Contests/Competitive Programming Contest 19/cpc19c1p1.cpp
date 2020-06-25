#include <iostream>

using namespace std;

int main() {
    int house;
    cin >> house;
    int start = 1, finish = house;
    for (int i = 0; i < house; i++){
        if (i % 2 == 0){
            cout << start << " ";
            start += 1;
        }
        else{
            cout << finish << " ";
            finish -= 1;
        }
    }
}