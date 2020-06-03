#Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/ 
class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        a = set()
        b = set()
        da = {}
        for s in A.split(" "):
            a.add(s)
            da[s] = da.get(s,0)+1
            
        for s in B.split(" "):
            b.add(s)
            da[s] = da.get(s,0)+1
            
        for k,v in da.items():
            if v > 1:
                if k in a:
                    a.remove(k)
                if k in b:
                    b.remove(k)
        
        return list(a ^ b)