#Link: https://leetcode.com/problems/top-k-frequent-words/ 
class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        if( k == 0 ):
            return []
        from collections import Counter
        import operator
        count = [(v,key) for key, v in Counter(words).items()]
        def func(x, y):
            if( x[0]>y[0] ):
                return 1
            if( x[0]<y[0] ):
                return -1
            if(x[0] == y[0]):
                if x[1]<y[1] :
                    return 1
                else:
                    return -1;
            return 0
        count.sort(cmp=func, reverse=True)
        return [word for cnt, word in count[0:k]]