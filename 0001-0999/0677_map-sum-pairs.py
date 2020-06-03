#Link: https://leetcode.com/problems/map-sum-pairs/ 
class MapSum(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data={}

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """
        self.data[key] = val

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        
        return sum([v for k,v in self.data.iteritems() if k.startswith(prefix)>0 ])


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)