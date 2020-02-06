#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    string m, d;
    cin >> m >> d;
    int n;
    cin >> n;
    while (n--){
        string b;
        cin >> b;
        bool baby = true;
        for (int i = 0; i < b.length(); i++){
            if (islower(b[i])){
                if (((isupper(m[i]) && isupper(m[i+1])) || (isupper(d[i]) && isupper(d[i+1])))){
                    baby = false;
                }
            }
            else {
                if (islower(m[i]) && islower(m[i+1]) && islower(d[i]) && islower(d[i+1])){
                    baby = false;
                }
            }
        }
        if (baby){
            cout << "Not their baby!" << endl;
        }
        else {
            cout << "Possible baby." << endl;
        }
    }
}
