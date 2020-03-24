#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define inf 0x3f3f3f3f

long double total(vector<vector<int>> scores){
    long double cnt = scores.size();
    long double totalPerc = 0;
    for (int i = 0; i < scores.size(); i++){
        long double a = scores[i][0];
        long double b = scores[i][1];
        long double percent = a/b;
        totalPerc += percent;
    }
    return totalPerc / cnt;
}

int passExam(vector<vector<int>> &scores, int r) {
    int cnt = 0;
    long double totalScore;
    while (true){
        long double highest = 0;
        int highestInd = 0;
        long double highestA = 0, highestB = 0;
        for (int i = 0; i < scores.size(); i++){
            long double a = scores[i][0];
            long double b = scores[i][1];
            scores[i][0]++;
            scores[i][1]++;
            long double perc = total(scores);
            if (perc >= (long double)r/100){
                cnt++;
                goto done;
            }
            else if (perc > highest){
                highestInd = i;
                highest = perc;
                highestA = a;
                highestB = b;
            }
            else if (abs(perc - highest) < 1e-8){
                if (a < highestA && b < highestB){
                    highestInd = i;
                    highest = perc;
                    highestA = a;
                    highestB = b;
                }
            }
            scores[i][0]--;
            scores[i][1]--;
        }
        cnt++;
        scores[highestInd][0]++;
        scores[highestInd][1]++;
    }
    done:
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vi> vec = {{1,2}, {1,2}};
    cout << passExam(vec, 67);
}