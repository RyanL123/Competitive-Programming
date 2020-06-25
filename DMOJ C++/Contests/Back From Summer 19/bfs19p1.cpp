#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m, cute, least = 0;
    scanf("%i%i", &n, &m);
    int orphan[n][m], overallCute[n];
    for (int i = 0; i < n; i++){
        overallCute[i] = 0;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%i", &cute);
            if (cute == 1 || cute == 10){
                overallCute[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (overallCute[i] < overallCute[least]){
            least = i;
        }
    }
    printf("%i", least+1);
}