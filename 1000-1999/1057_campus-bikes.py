#Link: https://leetcode.com/problems/campus-bikes/ 
class Solution(object):
    def assignBikes(self, workers, bikes):
        """
        :type workers: List[List[int]]
        :type bikes: List[List[int]]
        :rtype: List[int]
        """
        distances = []
        for i, worker in enumerate(workers):
            for j, bike in enumerate(bikes):
                distance = abs(worker[0] - bike[0]) + abs(worker[1] - bike[1])
                distances.append((distance, i, j))
        distances.sort()
        
        eleset = set()
        res = [-1] * len(workers)
        for d, w, b in distances:
            if res[w] == -1 and b not in eleset:
                res[w] = b
                eleset.add(b)
        return res