#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int year, month, day;
        cin >> year >> month >> day;
        if (2007 - year > 18){
            cout << "Yes\n";
        }
        else if (2007 - year == 18){
            if (month < 2){
                cout << "Yes\n";
            }
            else if (month == 2){
                if (day <= 27){
                    cout << "Yes\n";
                }
                else {
                    cout << "No\n";
                }
            }
            else{
                cout << "No\n";
            }
        }
        else {
            cout << "No\n";
        }
    }
}
