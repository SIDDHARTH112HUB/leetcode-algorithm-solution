//Link: https://leetcode.com/problems/construct-target-array-with-multiple-sums/ 
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        for(long long n : target) sum += n;
        priority_queue<int> pq;
        for(int n : target)
            pq.push(n);
        while(pq.size()) {
            int n = pq.top();
            pq.pop();
            if(n == 1) return pq.size() + 1 == target.size();
            if(sum <= n) return false;
            if(n <= sum - n) return false;
            int m = n % (sum - n);
            pq.push(m);
            sum = sum - n + m;
        }
        return false;
    }
};