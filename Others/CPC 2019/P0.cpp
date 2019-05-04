#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> left;
    vector<int> right;
    char shoe;
    for (int i = 1; i <= 4; i++){
        cin >> shoe;
        if (shoe == 'L'){
            left.push_back(i);
        }
        else{
            right.push_back(i);
        }
    }

    cout << left[0] << " " << right[0] << endl;
    cout << left[1] << " " << right[1] << endl;
}