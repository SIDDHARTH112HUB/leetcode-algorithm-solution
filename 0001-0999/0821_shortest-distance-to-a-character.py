#Link: https://leetcode.com/problems/shortest-distance-to-a-character/ 
class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        C_list = []
        for idx, char_s in enumerate(S):
            if char_s == C:
                C_list.append(idx)
        ans = []
        for idx, char_s in enumerate(S):
            if char_s != C:
                min_dis = 1000000
                for c_idx in C_list:
                    dis = abs(c_idx - idx)
                    if dis < min_dis:
                        min_dis = dis
                ans.append(min_dis)
            else:
                ans.append(0)
        return ans