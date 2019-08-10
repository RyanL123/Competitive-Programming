#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n,k, score;
    int scores [101]{0};
    int worstRank[101]{1};
    int ranks[101];

    scanf("%i%i", &n, &k);

    //records rankings after each round
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            scanf("%i", &score);
            scores[j] += score;
        }
        for (int j = 0; j < n; j++){
            int ranksBehind = 1;
            for (int c = 0; c < n; c++){
                if (c != j && scores[c] > scores[j]){
                    ranksBehind++;
                }
            }
            if (ranksBehind > worstRank[j]){
                worstRank[j] = ranksBehind;
            }
            ranks[j] = ranksBehind;
        }

    }
    for (int i = 0; i < n; i++){
        if (ranks[i] == 1){
            printf("Yodeller %i is the TopYodeller: score %i, worst rank %i\n", i+1, scores[i], worstRank[i]);
        }
    }
}
