#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int largestIndex(int arr[]){
    int index = 1;
    for (int j = 1; j <= 26; j++){
        if (arr[j] > arr[index]){
            index = j;
        }
    }
    return index;
}
int main() {
    string s;
    cin >> s;
    int l, k, count[100], total = 0;
    scanf("%i%i", &l, &k);

    if (k == s.length()){
        printf("0");
        return 0;
    }
    //intialize count
    for (int i = 0; i <= 26; i++){
        count[i] = 0;
    }
    //record count for each character
    for (int i = 0; i < s.length(); i++){
        count[s[i]-96]++;
    }
    //remove k characters
    for (int i = 0; i < k; i++){
        int largest = largestIndex(count);
        count[largest]--;
    }
    for (int i = 1; i <= 26; i++){
        total += count[i]*count[i];
    }
    printf("%i", total);
}