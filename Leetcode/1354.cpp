class Solution {
public:
    // sum strictly increases
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> pq;
        for (int i : target) {
            sum += i;
            pq.push(i);
        }
        while (!pq.empty()) {
            // greatest element, sum of rest of elements excluding greatest
            long long i = pq.top(), j = sum - i;
            if (i == 1) break; // greatest element is 1, done
            if (j == 0) return i == 1; // there is only 1 element, it must be 1
            pq.pop(); // remove greatest
            if (i-j <= 0) return false; // greatest element is less than the rest of array, impossible
            // greatest element divides perfectly into sum of rest of array, but don't reduce it to 0
            if (i%j == 0) {
                pq.push(j); // if i%j == 0, lowest number I can keep is 1 instance of j
                sum -= i;
                sum += j;
            }
            // greatest element does not divide perfectly, subtract as much as possible and keep remainder
            else {
                pq.push(i%j); // keep only the remainder
                sum -= i;
                sum += i%j;
            }
        }
        return true;
    }
};