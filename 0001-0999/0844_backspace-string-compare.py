#Link: https://leetcode.com/problems/backspace-string-compare/ 
class Solution:
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        s = list(S);
        t = list(T);
        s.append(0)
        t.append(0)
        p = 0;
        string = s
        for idx, i in enumerate(string):
            if( i == '#'):
                if( p > 0):
                    p -= 1
                string[p] = 0; 
            else:
                string[p] = i
                p += 1;
        string = t;
        p = 0
        for idx, i in enumerate(string):
            if( i == '#'):
                if( p > 0):
                    p -= 1
                string[p] = 0; 
            else:
                string[p] = i
                p += 1;
        
        l = min(len(s), len(t))
        for i in range(l):
            if( s[i] != t[i]):
                return False;
            if( s[i] == t[i] and t[i] == 0 ):
                return True
        return False