#Link: https://leetcode.com/problems/24-game/ 
class Solution(object):
    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        import itertools
        per = list(itertools.permutations(nums,4))
        import operator
        oper = [operator.add, operator.sub, operator.mul, lambda x,y:operator.truediv(x, y or 0.000001), lambda x,y: operator.sub(y,x), lambda x,y: operator.truediv(y,x or 0.000001)]
        for fournum in per:
            for op1 in oper:
                for op2 in oper:
                    for op3 in oper:
                        #per = list(itertools.permutations(fournum,4))
                        res = op3(op2(op1(fournum[0],fournum[1]), fournum[2]), fournum[3]) # 1 2 3 4
                        #print(fournum, op1, op2, op3, res)
                        if abs(res - 24) < 0.01:
                            return True
                        res = op3(op1(fournum[0],fournum[1]), op2(fournum[2], fournum[3])) # (1 2) ( 3 4)
                        if abs(res - 24) < 0.01:
                            return True
                        res = op3(fournum[0], op2((fournum[1]), op1(fournum[2], fournum[3]))) #( 4 (3 (1 2) )
                        if abs(res - 24) < 0.01:
                            return True
                        res = op3(fournum[0], op1(op2(fournum[1], fournum[2]), fournum[3]))  # ( 4 ( (1 2) 3) )
                        if abs(res - 24) < 0.01:
                            return True
                        res = op1(op3(fournum[0], op2(fournum[1], fournum[2])), fournum[3])  # ( 4 (1 2))  3) 
                        if abs(res - 24) < 0.01:
                            return True
        return False