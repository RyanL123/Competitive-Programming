#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m, total = 0;
    int q, d = 0, p = -1;
    vector<pair<int, int>> prices;
    vector<int> usedDays;
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++){
        int previousDay = d;
        int previousDayPrice = p;
        cin >> d >> p;

        if (previousDay != d && previousDayPrice != -1){
            for (int i = 1; i <= abs(previousDay-d); i++){
                prices.push_back(make_pair(previousDayPrice, previousDay-i));
            }
        }
        prices.push_back(make_pair(p, d));
    }

    // Sort by price
    sort(prices.begin(), prices.end());

    int count = 0;
    for (int i = 0; i < prices.size(); i++){
        // Buy m times
        if (count == m){
            break;
        }
        // Ignores days that have already been used to buy a costume
        if (find(usedDays.begin(), usedDays.end(), prices[i].second) == usedDays.end()){
            // Record the day bought and add the price to the total
            total += prices[i].first;
            usedDays.push_back(prices[i].second);
            count++;
        }
    }
    cout << total << endl;
}