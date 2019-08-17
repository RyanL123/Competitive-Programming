#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void connect(vector<int> g[], int x, int y){
    bool xY = false;
    bool yX = false;
    for (int i = 0; i < g[x].size(); i++){
        if (g[x][i] == y){
            xY = true;
            break;
        }
    }
    for (int i = 0; i < g[y].size(); i++){
        if (g[y][i] == x){
            yX = true;
            break;
        }
    }
    if (!xY){
        g[x].push_back(y);
    }
    if (!yX){
        g[y].push_back(x);
    }
}
void disconnect(vector<int> g[], int x, int y){
    for (int i = 0; i < g[x].size(); i++){
        if (g[x][i] == y) {
            g[x].erase(g[x].begin() + i);
            break;
        }
    }
    for (int i = 0; i < g[y].size(); i++){
        if (g[y][i] == x) {
            g[y].erase(g[y].begin() + i);
            break;
        }
    }
}
int friends(vector<int> g[], int x){
    return g[x].size();
}
int friendsOfFriends(vector<int> g[], int x){
    int steps[51], count = 0;
    fill_n(steps, 51, 99);
    queue<int> q;
    q.push(x);
    steps[x] = 0;
    //BFS
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for (int i = 0; i < g[f].size(); i++){
            if (steps[g[f][i]] > steps[f]+1){
                q.push(g[f][i]);
                steps[g[f][i]] = steps[f]+1;
            }
        }
    }
    for (int i = 0; i < 51; i++){
        if (steps[i] == 2){
            count++;
        }
    }
    return count;
}
int separation(vector<int> g[], int x, int y){
    int steps[51], count = 0;
    fill_n(steps, 51, 99);
    queue<int> q;
    q.push(x);
    steps[x] = 0;
    //BFS
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for (int i = 0; i < g[f].size(); i++){
            if (steps[g[f][i]] > steps[f]+1){
                q.push(g[f][i]);
                steps[g[f][i]] = steps[f]+1;
            }
        }
    }
    if (steps[y] == 99) return -1;
    return steps[y];
}
int main() {
    vector<int> graph[51] = {
            {},
            {6},
            {6},
            {4,5,6,15},
            {3,5,6},
            {3,4,6},
            {1,2,3,4,5,7},
            {6,8},
            {7,9},
            {8,10,12},
            {9,11},
            {10,12},
            {9,11,13},
            {12,14,15},
            {13},
            {3,13},
            {17,18},
            {16,18},
            {16,17}
    };
    while (true){
        char command;
        int x,y;
        scanf("%c", &command);
        if (command == 'q'){
            break;
        }
        if (command == 'i'){
            scanf("%i%i", &x, &y);
            connect(graph, x, y);
        }
        else if (command == 'd'){
            scanf("%i%i", &x, &y);
            disconnect(graph, x, y);
        }
        else if (command == 'n'){
            scanf("%i", &x);
            printf("%i\n", friends(graph,x));
        }
        else if (command == 'f'){
            scanf("%i", &x);
            printf("%i\n", friendsOfFriends(graph, x));
        }
        else if (command == 's'){
            scanf("%i%i", &x, &y);
            int degree = separation(graph, x, y);
            if (degree == -1){
                printf("Not connected\n");
            }
            else {
                printf("%i\n", degree);
            }

        }

    }

}