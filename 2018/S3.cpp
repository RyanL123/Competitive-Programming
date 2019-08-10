#include <iostream>
#include <cstdio>
#include <vector>
#define first queue[0]
#define second queue[1]

using namespace std;

int main() {
    int n,m;
    string input;
    vector<int> queue;
    char factory[110][110];
    int steps[110][110];
    for (int i = 0; i < 110; i++){
        for (int j = 0; j < 110; j++){
            factory[i][j] = 'x';
            steps[i][j] = 999;
        }
    }

    //gets factory floor plan
    scanf("%i%i", &n, &m);
    for (int i = n-1; i >= 0; i--){
        cin >> input;
        for (int j = sizeof(input)-1; j >= 0; j--) {
            factory[i][j] = input[j];
            if (input[j] == 'S'){
                queue.push_back(i);
                queue.push_back(j);
                steps[i][j] = 0;
            }
        }
    }

    //BFS
    while (!queue.empty()){
        //check up
        if (factory[first+1][second] != 'W' && factory[first+1][second] != 'C'
        && steps[first+1][second] > steps[first][second]){
            //if the adjacent block is a conveyor belt
            if (factory[first+1][second] == 'D'){
                if (factory[first][second] == '.' || factory[first][second] == 'S'){
                    steps[first+1][second] = steps[first][second]+1;
                }
                else{
                    steps[first+1][second] = steps[first][second];
                }
                steps[first+1][second] = steps[first][second];
                queue.push_back(first+1);
                queue.push_back(second);
            }
            else if (factory[first+1][second] == 'U'){
                if (factory[first][second] == '.' || factory[first][second] == 'S'){
                    steps[first+1][second] = steps[first][second]+1;
                }
                else{
                    steps[first+1][second] = steps[first][second];
                }
                queue.push_back(first+1);
                queue.push_back(second);
            }
            else if (factory[first+1][second] == 'L'){
                if (factory[first][second] == '.' || factory[first][second] == 'S'){
                    steps[first+1][second] = steps[first][second]+1;
                }
                else{
                    steps[first+1][second] = steps[first][second];
                }
                queue.push_back(first+1);
                queue.push_back(second);
            }
            else if (factory[first+1][second] == 'R'){
                if (factory[first][second] == '.' || factory[first][second] == 'S'){
                    steps[first+1][second] = steps[first][second]+1;
                }
                else{
                    steps[first+1][second] = steps[first][second];
                }
                queue.push_back(first+1);
                queue.push_back(second);
            }
            else{
                steps[first+1][second] = steps[first][second]+1;
                queue.push_back(first+1);
                queue.push_back(second);
            }
        }
        //check down
        if (factory[first-1][second] != 'W' && factory[first-1][second] != 'C'
        && steps[first-1][second] > steps[first][second]){
            if (factory[first-1][second] == 'D'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first-1][second] = steps[first][second]+1;
                }
                else {
                    steps[first - 1][second] = steps[first][second];
                }
                queue.push_back(first+1);
                queue.push_back(second);
            }
            else if (factory[first-1][second] == 'U'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first-1][second] = steps[first][second]+1;
                }
                else {
                    steps[first - 1][second] = steps[first][second];
                }
                queue.push_back(first+1);
                queue.push_back(second);
            }
            else if (factory[first-1][second] == 'L'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first-1][second] = steps[first][second]+1;
                }
                else {
                    steps[first - 1][second] = steps[first][second];
                }
                queue.push_back(first+1);
                queue.push_back(second);
            }
            else if (factory[first-1][second] == 'R'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first-1][second] = steps[first][second]+1;
                }
                else {
                    steps[first - 1][second] = steps[first][second];
                }
                queue.push_back(first-1);
                queue.push_back(second);
            }
            else{
                steps[first-1][second] = steps[first][second]+1;
                queue.push_back(first-1);
                queue.push_back(second);
            }
        }
        //check right
        if (factory[first][second+1] != 'W' && factory[first][second+1] != 'C'
        && steps[first][second+1] > steps[first][second]){
            if (factory[first][second+1] == 'D'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first][second+1] = steps[first][second]+1;
                }
                else{
                    steps[first][second+1] = steps[first][second];
                }
                queue.push_back(first);
                queue.push_back(second+1);
            }
            else if (factory[first][second+1] == 'U'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first][second+1] = steps[first][second]+1;
                }
                else{
                    steps[first][second+1] = steps[first][second];
                }
                queue.push_back(first);
                queue.push_back(second+1);
            }
            else if (factory[first][second+1] == 'L'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first][second+1] = steps[first][second]+1;
                }
                else{
                    steps[first][second+1] = steps[first][second];
                }
                queue.push_back(first);
                queue.push_back(second+1);
            }
            else if (factory[first][second+1] == 'R'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first][second+1] = steps[first][second]+1;
                }
                else{
                    steps[first][second+1] = steps[first][second];
                }
                queue.push_back(first);
                queue.push_back(second+1);
            }
            else{
                steps[first][second+1] = steps[first][second]+1;
                queue.push_back(first);
                queue.push_back(second+1);
            }
        }
        //check left
        if (factory[first][second-1] != 'W' && factory[first][second-1] != 'C'
        && steps[first][second-1] > steps[first][second]){
            if (factory[first][second-1] == 'D'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first][second-1] = steps[first][second]+1;
                }
                else{
                    steps[first][second-1] = steps[first][second];
                }
                queue.push_back(first);
                queue.push_back(second+1);
            }
            else if (factory[first][second-1] == 'U'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first][second-1] = steps[first][second]+1;
                }
                else{
                    steps[first][second-1] = steps[first][second];
                }
                queue.push_back(first);
                queue.push_back(second-1);
            }
            else if (factory[first][second-1] == 'L'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first][second-1] = steps[first][second]+1;
                }
                else{
                    steps[first][second-1] = steps[first][second];
                }
                queue.push_back(first);
                queue.push_back(second-1);
            }
            else if (factory[first][second-1] == 'R'){
                if (factory[first][second] == '.' || factory[first][second] == 'S') {
                    steps[first][second-1] = steps[first][second]+1;
                }
                else{
                    steps[first][second-1] = steps[first][second];
                }
                queue.push_back(first);
                queue.push_back(second-1);
            }
            else{
                steps[first][second-1] = steps[first][second]+1;
                queue.push_back(first);
                queue.push_back(second-1);
            }
        }
        queue.erase(queue.begin());
        queue.erase(queue.begin());
    }

    //print steps
    for (int i = n-1; i >= 0; i--){
        for (int j = 0; j < m; j++){
            if (factory[i][j] == '.' && steps[i][j] == 999) {
                printf("-1\n");
            }
            else if (factory[i][j] == '.'){
                printf("%i\n", steps[i][j]);
            }
        }
    }

}