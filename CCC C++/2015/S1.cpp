#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k,a,total = 0;
    vector<int> numbers {};

    cin >> k;

    for (int i = 0; i < k; i++){
        cin >> a;
        if (a!=0) numbers.push_back(a);
        else numbers.pop_back();
    }

    for (int i = 0; i < numbers.size(); i++){
        total += numbers[i];
    }

    cout << total << endl;
}
