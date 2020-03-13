#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        bool valid = true;
        stack<char> st;
        for (int j = 0; j < s.length(); j++){
            if (s[j] == '('){
                st.push('(');
            }
            if (s[j] == ')'){
                if (st.empty() || st.top() != '('){
                    valid = false;
                }
                else if (st.top() == '('){
                    st.pop();
                }
            }
        }
        if (!st.empty()){
            valid = false;
        }
        if (valid){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}