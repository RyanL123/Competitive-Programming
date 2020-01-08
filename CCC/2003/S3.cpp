#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int rooms[30][30];
int roomsTileCount[630];

bool desc(const int &a, const int &b){
    return a > b;
}
int main() {
    int tiles, r, c, currentRoom = 1;
    cin >> tiles >> r >> c;
    string graph[r], s;

    for (int i = 0; i < r; i++){
        cin >> s;
        graph[i] = s;
    }
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (graph[i][j] != 'I'){
                if (rooms[i][j] == 0){
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    while (!q.empty()){
                        int first = q.front().first;
                        int second = q.front().second;
                        q.pop();
                        if (first+1 < r && graph[first+1][second] != 'I' && rooms[first+1][second] == 0){
                            rooms[first+1][second] = currentRoom;
                            roomsTileCount[currentRoom]++;
                            q.push(make_pair(first+1, second));
                        }
                        if (first-1 >= 0 && graph[first-1][second] != 'I' && rooms[first-1][second] == 0){
                            rooms[first-1][second] = currentRoom;
                            roomsTileCount[currentRoom]++;
                            q.push(make_pair(first-1, second));
                        }
                        if (second+1 < c && graph[first][second+1] != 'I' && rooms[first][second+1] == 0){
                            rooms[first][second+1] = currentRoom;
                            roomsTileCount[currentRoom]++;
                            q.push(make_pair(first, second+1));
                        }
                        if (second-1 >= 0 && graph[first][second-1] != 'I' && rooms[first][second-1] == 0){
                            rooms[first][second-1] = currentRoom;
                            roomsTileCount[currentRoom]++;
                            q.push(make_pair(first, second-1));
                        }
                    }
                    currentRoom++;
                }
            }
        }
    }
    sort(begin(roomsTileCount), end(roomsTileCount), desc);
    int finalRoomsCount = 0, i = 0;
    while (true){
        if (tiles - roomsTileCount[i] < 0 || roomsTileCount[i] == 0){
            break;
        }
        tiles -= roomsTileCount[i];
        i++;
        finalRoomsCount++;
    }
    if (finalRoomsCount == 1){
        cout << "1 room, " << tiles << " square metre(s) left over";
    }
    else {
        cout << finalRoomsCount << " rooms, " << tiles << " square metre(s) left over";
    }
}