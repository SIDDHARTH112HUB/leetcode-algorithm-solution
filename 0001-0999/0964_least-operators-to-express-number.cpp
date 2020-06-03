//Link: https://leetcode.com/problems/least-operators-to-express-number/ 
class Solution {
public:
    unordered_map<int, int> m;
    int leastOpsExpressTarget(int x, int target) {
        if( m.count(target )) return m[target];
        if( x > target ){
            return min( target*2-1, (x - target)*2  );
        }
        long long sum  = x;
        int ans = 0;
        while( sum < target){
            sum *= x;
            ++ans;
        }
        if( sum == target ) return ans;
        int l = INT_MAX, r = INT_MAX;
        if( sum - target < target ){
            l = leastOpsExpressTarget(x, sum - target);
        }
        r = leastOpsExpressTarget(x, target-sum/x)-1;
        m[target] = min(l, r) + ans+1;
        return m[target];
    }
};