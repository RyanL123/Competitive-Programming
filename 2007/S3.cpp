#include <iostream>

using namespace std;

int main() {
    int n,x,y;
    cin >> n;
    int friends[10005];
    bool visited[10005];

    //creates graph of friends
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        friends[x] = y;
    }

    //checks for a cycle
    while (true){
        cin >> x >> y;
        if (x == 0 && y == 0){
            break;
        }

        //initializes visited array
        for (int i = 1; i < n+1; i++){
            visited[i] = false;
        }

        //counts the cycle if there is one, or output no
        int counter = -1;
        while (true){
            if (x == y){
                cout << "Yes " << counter << endl;
                break;
            }
            else if (visited[x]){
                cout << "No" << endl;
                break;
            }
            visited[x] = true;
            x = friends[x];
            counter++;
        }
    }
}