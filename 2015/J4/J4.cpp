#include <iostream>

using namespace std;

int main(){
    int m,counter = 0;

    cin >> m;

    int friends[101] = {0};
    int wait[101] = {0};
    int lastSent[101] = {0};
    int reply[101] = {0};

    for (int i = 0; i < m; i++){

        //gets each line of input
        int fr;
        char status;

        cin >> status >> fr;

        //gets status of message

        //if read, updates the last sent time
        if (status == 'R'){

            //records the friend who sent the message
            if (friends[fr] != 1){
                friends[fr] = 1;
            }

            //updates last sent time
            lastSent[fr] = counter;

            counter++;


        }
        //if wait, add the wait time, then subtract the previous +1
        else if (status == 'W'){
            //adds the recorded wait time
            counter += fr;

            counter--;

        }

        //if sent, records the time elapsed in the wait array, then sets the last sent time
        else if (status == 'S'){

            //records the amount of time that friend has been waiting
            wait[fr] += counter - lastSent[fr];

            lastSent[fr] = counter;

            counter++;

            reply[fr] = 1;
        }
    }

    //prints the wait time for each friend
    for (int i = 0; i < 101; i++){
        if (friends[i] != 0){
            if (reply[i] == 0){
                cout << i << " -1"<< endl;
            }
            else{
                cout << i << " " << wait[i] << endl;
            }

        }

    }
}
