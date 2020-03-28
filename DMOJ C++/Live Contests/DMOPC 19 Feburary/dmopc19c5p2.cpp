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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<string, int>> charlie;
    vector<pair<string, int>> op;
    int n, h;
    cin >> n >> h;
    int cH = h;
    int pH = h;
    for (int i = 0; i < n; i++){
        string s;
        int a;
        cin >> s >> a;
        charlie.pb(mp(s, a));
    }
    for (int i = 0; i < n; i++){
        string s;
        int a;
        cin >> s >> a;
        op.pb(mp(s, a));
    }
    bool cDodge = false;
    int cDmg = 0;
    bool pDodge = false;
    int pDmg = 0;
    for (int i = 0; i < n; i++){
        if (charlie[i].first == "A"){
            if (pDodge){
                pDodge = false;
            }
            else {
                pH -= charlie[i].second;
            }
        }
        else {
            cDodge = true;
            cDmg = charlie[i].second;
            if (pDodge){
                pH -= pDmg;
                pDodge = false;
                pDmg = 0;
            }
        }
        if (pH <= 0){
            cout << "VICTORY";
            return 0;
        }
        if (op[i].first == "A"){
            if (cDodge){
                cDodge = false;
            }
            else {
                cH -= op[i].second;
            }
        }
        else {
            pDodge = true;
            pDmg = op[i].second;
            if (cDodge){
                cH -= cDmg;
                cDodge = false;
                cDmg = 0;
            }
        }
        if (cH <= 0){
            cout << "DEFEAT";
            return 0;
        }
    }
    if (pDodge){
        pH -= pDmg;
    }
    if (pH <= 0){
        cout << "VICTORY";
    }
    else cout << "TIE";
}