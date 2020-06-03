#Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/ 
class Solution(object):
    def numSteps(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = int(s, 2);
        ans = 0;
        while num > 1:
            if num % 2:
                num += 1;
            else:
                num //= 2;
            ans += 1;
        return ans;