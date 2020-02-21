#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    long long int t, n, m = 998244353, happiness = 0;
    scanf("%lli%lli", &n, &t);
    priority_queue<tuple<long long int, long long int, long long int, long long int>> pq;
    for (int i = 1; i <= n; i++){
        long long int a, b;
        scanf("%lli%lli", &a, &b);
        long long val = max(0, (int)(a-(0)*b));
        pq.push(make_tuple(val, a, b, 1));
    }
    while (t != 0){
        long long int val = get<0>(pq.top());
        long long int a = get<1>(pq.top());
        long long int b = get<2>(pq.top());
        long long int count = get<3>(pq.top())+1;
        pq.pop();
        happiness += val%m;
        val = max((long long int)0, (a-(count-1)*b));
        pq.push(make_tuple(val, a, b, count+1));
        t--;
    }
    printf("%lli\n", happiness%m);
}