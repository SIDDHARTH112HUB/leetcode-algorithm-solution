#Link: https://leetcode.com/problems/sentence-similarity/ 
class Solution(object):
    def areSentencesSimilar(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        pair_dict = {}
        for pair in pairs:
            pair_dict[pair[0] +"_" + pair[1]] = 1
            pair_dict[pair[1] +"_" + pair[0]] = 1
            
        l1 = len(words1)
        l2 = len(words2)
        if( l1 != l2 ):
            return False
        l = l1<l2 and l1 or l2
        for i in range(l):
            if not ( words1[i] == words2[i] or (pair_dict.get(words1[i] +"_" +words2[i])) ):
                return False;
        return True