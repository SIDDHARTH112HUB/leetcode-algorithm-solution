#Link: https://leetcode.com/problems/redundant-connection-ii/ 
class Solution(object):
    def findRedundantDirectedConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        u = {}
        idx = 1;
        child = {}
        res = [[]];
        for e in edges:
            p = e[0]
            c = e[1]
            u1 = u.get(p, 0)
            u2 = u.get(c, 0)
            if child.get(c,0) > 0:
                res.append(e);
                continue
            if u1 != u2:
                if u1 > 0 and u2 > 0:
                    for k,v in u.items():
                        if v == u2:
                            del u[k]
                            u[k] = u1
                elif u1 == 0:
                    u[p] = u2
                elif u2 == 0:
                    u[c] = u1
            else:
                if u1>0:
                    res.append(e);
                    continue
                idx+=1
                u[p] = idx
                u[c] = idx
            child[c] = p
        return res[-1]
            
            