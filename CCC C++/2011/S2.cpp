#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, count=0;
    char input;
    vector<char>student;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        student.push_back(input);
    }
    
    vector<char>answers;
    for (int i = 0; i < n; i++){
        cin >> input;
        answers.push_back(input);
    }
    
    for (int i = 0; i < n; i++){
        if (student[i] == answers[i]){
            count++;
        }
    }
    cout << count;
}
