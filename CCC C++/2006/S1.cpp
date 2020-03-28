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
                if (((isupper(m[2*i]) && isupper(m[2*i+1])) || (isupper(d[2*i]) && isupper(d[2*i+1])))){
                    baby = false;
                    break;
                }
            }
            else {
                if (islower(m[2*i]) && islower(m[2*i+1]) && islower(d[2*i]) && islower(d[2*i+1])){
                    baby = false;
                    break;
                }
            }
        }
        if (baby){
            cout << "Possible baby." << endl;
        }
        else {
            cout << "Not their baby!" << endl;
        }
    }
}
