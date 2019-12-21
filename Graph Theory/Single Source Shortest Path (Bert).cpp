#include <iostream>
#include <vector>
#include <queue>

#define INT_MAX 2147483647
#define mp(a, b) make_pair(a,b)

using namespace std;

int main() {
    //placeholder variables basically, also problem defined constants
    int n, e, u, v, w;

    //this is same as your priority queue, but it sorts by lowest total weight to that node
    priority_queue<pair<int, int>> next;
    cin >> n >> e;

    //again same as your graph vector (i think thats what you called it)
    vector<pair<int, int>> distance[n + 1];

    //shortest path array
    int sp[n + 1];

    //can probably get away without needing this
    bool notVisited[n + 1];
    for (int i = 1; i < n + 1; i++) {
    //initialize the notvisited and shortest path arrays
        notVisited[i] = true;
        sp[i] = INT_MAX;
    }

    for (int i = 0; i < e; i++) {
        cin >> u >> v >> w;
    //store the graph edges
        distance[u].push_back(mp(v, w));
        distance[v].push_back(mp(u, w));
    }

    //set up the stack, initializing it with a total path weight of 0 and starting node of 1
    next.push(mp(0, 1));

    //initialize starting node to have shortest path 0
    sp[1] = 0;

    while (!next.empty()) {
    //the while true that you have as well
    //initialize w to be the total weight to get to that node using specified path and v to be current vertex
        w = -next.top().first;
        v = next.top().second;
    //set that we have visited v
        notVisited[v] = false;
    //pop next to remove it as we just stored the info
        next.pop();
    //so check if the total weight is larger than the current shortest path to v
    /* this is the linear coefficient optimization using the big brain negative shit
    by using shortest path you guarantee that the first time you reach v the stored sp is going to be one of the smallest you can achieve
    then using continue statement you can skip all the math after it so you save on computing power

    to see demonstration just compare your run time with my run time */
        if (w > sp[v]) continue;
        for (pair<int, int> p : distance[v]) {
    //second optimization, where again you only do math if you you havent visited the node
            if (notVisited[p.first]) {
                if (sp[p.first] >= p.second + w) {
    //basic comparator math to set sp to min value
                    sp[p.first] = p.second + w;
    //put that node onto the priority queue for processing next
                    next.push(mp(-(p.second + w), p.first));
                }
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
    //print the shortest path
        if (sp[i] == INT_MAX) cout << -1 << endl;
        else cout << sp[i] << endl;
    }
    return 0;
}