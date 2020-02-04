#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

int main() {
    map<pair<int, int>, int> saltExists;
    map<int, int> cordCountX;
    map<int, int> cordCountY;
    int n, q, x, y, qType;
    char type;
    cin >> n >> q;
    while (n--){
        scanf("%i%i", &x, &y);
        cordCountX[x]++;
        cordCountY[y]++;
        saltExists[make_pair(x, y)]++;
    }
    while (q--){
        scanf("%i", &qType);
        if (qType == 1){
            scanf("%i%i", &x, &y);
            if (saltExists[make_pair(x, y)]){
                printf("salty\n");
            }
            else {
                printf("bland\n");
            }
        }
        else {
            scanf(" %c %i", &type, &x);
            if (type == 'X'){
                printf("%i\n", cordCountX[x]);
            }
            else {
                printf("%i\n", cordCountY[x]);
            }
        }
    }
}