#Link: https://leetcode.com/problems/bulls-and-cows/ 
class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        ds = {}
        dg = {}
        bull = 0
        cow = 0
        
        for idx,s in enumerate(secret):
            g = guess[idx]
            if( s == g ):
                bull+=1
            else:
                ds[s] = ds.get(s,0)+1
                dg[g] = dg.get(g,0)+1

        for k, v in ds.items():
            ng = dg.get(k,0)
            cow += min(ng, v)
        return str(bull)+"A"+str(cow)+"B"