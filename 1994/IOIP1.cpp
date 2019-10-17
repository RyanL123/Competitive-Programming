#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin >> n;
    int dp[1000][1000];
    vector<vector<int>> triangle;
    for (int i = 0; i <= n; i++){
        triangle.push_back({});
        for (int j = 0; j < i; j++){
            int num;
            cin >> num;
            triangle[i].push_back(num);
        }
    }
    dp[1][0] = triangle[1][0];
    for (int i = 2; i < triangle.size(); i++){
        for (int j = 0; j < triangle[i].size(); j++){
            if (j == 0){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if (j == triangle[i].size()-1){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }
    }
    int max = -1;
    for (int i = 0; i < n; i++){
        if (dp[n][i] > max){
            max = dp[n][i];
        }
    }
    cout << max;
}