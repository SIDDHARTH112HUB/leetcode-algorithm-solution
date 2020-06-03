#Link: https://leetcode.com/problems/next-closest-time/ 
class Solution(object):
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        t = time.split(":")
        ct = int(t[0]) * 60 + int(t[1]);
        l = []
        
        minT = 1000000000;
        for c in time:
            if c != ":":
                l.append(int(c))
        res = time;
        for a in l:
            for b in l:
                for c in l:
                    for d in l:
                        h = a*10+b
                        m = c*10+d
                        if h<24 and m <60:
                            tt = h*60+m
                            if tt == ct:
                                continue
                            if tt < ct:
                                tt += 24*60
                            if tt < minT:
                                minT = tt
                                res = "%d%d:%d%d"%(a,b,c,d)
        return res;                        