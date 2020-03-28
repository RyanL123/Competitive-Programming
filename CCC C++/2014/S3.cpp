#include <iostream>
#include <stack>

using namespace std;

int main() {
    int t;
    cin >> t;
    // number of test cases
    for (int i = 0; i < t; i++){
        int n, car;
        cin >> n;
        stack<int> cars;
        stack<int> branch;
        bool order = true;

        // get cars order
        for (int j = 0; j < n; j++){
            cin >> car;
            cars.push(car);
        }
        for (int j = 1; j <= n; j++){
            // top car in order
            if (!cars.empty() && cars.top() == j){
                cars.pop();
            }
            // top car in branch in     order
            else if (!branch.empty() && branch.top() == j){
                branch.pop();
            }
            // top car is not in order
            else if (!cars.empty() && cars.top() != j){
                // keep sending cars to branch until the right order is found
                while (!cars.empty() && cars.top() != j){
                    branch.push(cars.top());
                    if (cars.empty()){
                        order = false;
                    }
                    else {
                        cars.pop();
                    }
                }
                if (!cars.empty()){
                    cars.pop();
                }
            }
            // Cars cannot be put in order
            else {
                order = false;
            }
        }
        if (order) {
            cout << "Y" << endl;
        }
        else {
            cout << "N" << endl;
        }
    }
}
