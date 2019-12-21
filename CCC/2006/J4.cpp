#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    //graph of the chores
    vector<int> todo[8];

    //initializes graph
    for (int i = 1; i < 8; i++){
        for (int j = 1; j < 8; j++){
            if (j != i){
                todo[i].push_back(j);
            }
        }
    }

    //sets the original constraints from the problem
    todo[7].erase(find(todo[7].begin(), todo[7].end(), 1));
    todo[4].erase(find(todo[4].begin(), todo[4].end(), 1));
    todo[1].erase(find(todo[1].begin(), todo[1].end(), 2));
    todo[4].erase(find(todo[4].begin(), todo[4].end(), 3));
    todo[5].erase(find(todo[5].begin(), todo[5].end(), 3));


    //gets additional restraints
    int x,y;

    while (true){
        cin >> x >> y;
        if (x == 0 || y == 0){
            break;
        }
        todo[y].erase(find(todo[y].begin(), todo[y].end(), x));
    }

    cout << 0;
}