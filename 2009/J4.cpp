#include <iostream>
#include <vector>

using namespace std;

int main(){
    int w, letter_count = 0, space_count = 0, word_count = 0;
    cin >> w;

    string words[] {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};
    vector<string> output {};
    vector<string> spaces {};

    //loops through words array
    for (int i = 0; i < 6; i++){

        //checks if the current line can fit the next word
        if (letter_count + words[i].length() <= w){

            //increases remaining letter count
            letter_count += words[i].length();

            //counts the amount of words on the current line
            word_count++;

            //adds the word to the output
            output.push_back(words[i]);
        }
        else {
            //if current line is full, add a linebreak to the output
            output.emplace_back("\n");

            //counts the amount of spaces needed for the current line
            space_count = w - letter_count;

            //if the spaces are equally apart
            if (space_count % word_count == 0){

            }
        }
    }
}

