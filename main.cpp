#include <iostream>
#include <vector>

using namespace std;

int main(){
    int input1, input2;
    vector<string> songs{"A","B","C","D","E"};


    while(true){
        cin >> input1 >> input2;

        if (input1 == 1){
            for (int i = 0; i < input2; i++){
                songs.push_back(songs[0]);
                songs.erase(songs.begin());
            }
        }
        else if (input1 == 2){
            for (int i = 0; i < input2; i++){

                songs.insert(songs.begin(), songs[4]);
                songs.erase(songs.end());
            }
        }
        else if (input1 == 3){
            if (input2%2==1){
                swap(songs[0], songs[1]);
            }
        }
        else{
            break;
        }

    }


    for (int i = 0; i < 5; i++){
        cout << songs[i] << " ";
    }
}
