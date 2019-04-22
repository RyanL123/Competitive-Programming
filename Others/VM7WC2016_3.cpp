#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m,a,b,house,house2;
    cin >> n >> m >> a >> b;

    //creates graph of the neighbourhood
    vector<int> houses[n+1];

    for (int i = 0; i < m; i++){
        scanf("%i %i", &house, &house2);
        houses[house].push_back(house2);
        houses[house2].push_back(house);
    }

    //bfs

    bool reachable = false;

    //initializes queue
    vector<int> queue;

    //initializes visited array to false
    bool visited[n+1];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }

    //first node is visited and added to queue
    visited[a] = true;
    queue.push_back(a);

    //erases the first node in queue and add its child nodes until the target is found
    while(true){
        //if they live in the same house
        if (a == b){
            reachable = true;
            break;
        }
        //target is found
        if (find(queue.begin(), queue.end(), b) != queue.end()){
            reachable = true;
            break;
        }
        //target is not reachable
        else if (queue.empty()){
            break;
        }

        //records the first node, erases it then add all the children that has not been visited
        int f = queue.front();
        queue.erase(queue.begin());

        //finds all child nodes of the parent node
        for (int i = 0; i < houses[f].size(); i++){
            //if the node has not been visited, add it to the queue
            if (!visited[houses[f][i]]){
                queue.push_back(houses[f][i]);
                visited[houses[f][i]] = true;
            }

        }
    }

    if (reachable){
        printf("GO SHAHIR!");
    }
    else {
        printf("NO SHAHIR!");
    }
}