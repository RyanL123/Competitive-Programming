#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int steps[11000];

int main() {
    int n, m, temp;
    vector<int> book[11000];
    vector<int> endingPages;
    scanf("%i", &n);

    //gets book pages and the options on each page
    for (int i = 1; i <= n; i++){
        scanf("%i", &m);
        if (m == 0){
            endingPages.push_back(i);
        }
        for (int j = 0; j < m; j++){
            scanf("%i", &temp);
            book[i].push_back(temp);
        }
    }

    //BFS

    for (int i = 0; i < 11000; i++){
        steps[i] = 11000;
    }
    steps[1] = 1;

    vector<int> queue;
    queue.push_back(1);

    while (!queue.empty()){
        //goes through every page the current page points to and records its steps,
        //then adds every page it points to;
        for (int i = 0; i < book[queue[0]].size(); i++) {
            if (steps[book[queue[0]][i]] > steps[queue[0]]+1) {
                steps[book[queue[0]][i]] = steps[queue[0]]+1;
                queue.push_back(book[queue[0]][i]);
            }
        }
        queue.erase(queue.begin());
    }

    //checks if every page is reachable
    bool reachable = true;
    int fastest = 11000;
    for (int i = 1; i <= n; i++){
        if (steps[i] == 11000){
            reachable = false;
        }
    }

    //finds shortest amount of steps to finish the book
    for (int i = 0; i < endingPages.size(); i++){
        if (steps[endingPages[i]] < fastest){
            fastest = steps[endingPages[i]];
        }
    }

    if (reachable) {
        printf("Y\n");
    }
    else {
        printf("N\n");
    }
    printf("%i", fastest);
}
