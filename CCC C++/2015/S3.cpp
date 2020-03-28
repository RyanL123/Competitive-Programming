#include <iostream>
#include <set>

using namespace std;

set<int> available;
int main() {
    int g, p, gi;
    cin >> g >> p;
    for (int i = 1; i <= g; i++){
        available.insert(-i);
    }
    for (int i = 0; i < p; i++){
        cin >> gi;
        // No gates are available
        // Lower_bound returns the element the doesn't compare less than
        // its parameter. Inserting the elements as negatives will reverse this
        if (available.lower_bound(-gi) == available.end()){
            cout << i;
            return 0;
        }
        // Gate is available and remove the gate
        available.erase(available.lower_bound(-gi));
    }
    cout << p;
}
