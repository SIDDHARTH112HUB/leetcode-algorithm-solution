//Link: https://leetcode.com/problems/sort-integers-by-the-power-value/ 
class Solution {
public:
    map<int, int> m;
    int getKth(int lo, int hi, int k) {
        for(int i = lo; i <= hi; ++i) {
            h(i);
        }
        priority_queue<pair<int, int> > pq;
        for(int i = lo; i <= hi; ++i) {
            pq.push({-m[i], -i});
        }
        while(k-- > 1) pq.pop();
        return -(pq.top().second);
    }
    int h(int n) {
        if(n == 1) return 0;
        int org = n;
        if(m.count(n))return m[n];
        if(n % 2 ) {
            n = 3 * n + 1;
        }else
            n /= 2;
        return m[org] = h(n) + 1;
    }
};