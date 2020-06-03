#Link: https://leetcode.com/problems/valid-parenthesis-string/ 
class Solution(object):
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        star = []
        p = []
        c=0
        for i in s:
            c+=1;
            if i == "(":
                p.append( (c, i))
            elif i == ")":
                if len(p):
                    p.pop()
                elif len(star):
                    star.pop()
                else:
                    return False
            else:
                star.append((c,i));
        lp = len(p)
        ls = len(star)
        if lp > ls:
            return False;
        p.sort(reverse=True)
        star.sort(reverse=True)
        #print(p, star)
        for idx, pitem in enumerate( p ):
            if pitem[0] > star[idx][0]:
                return False;
        return True