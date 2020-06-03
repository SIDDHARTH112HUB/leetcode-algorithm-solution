#Link: https://leetcode.com/problems/implement-magic-dictionary/ 
class MagicDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.d = {}

    def buildDict(self, dict):
        """
        Build a dictionary through a list of words
        :type dict: List[str]
        :rtype: void
        """
        for i in dict:
            self.d[i] = 1;

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        lw = len(word)
        for k,v in self.d.iteritems():
            cnt = 0
            lk = len(k)
            if lk != lw:
                continue
            wrong_num = 0
            for c in k:
                if c != word[cnt]:
                    wrong_num += 1
                cnt+=1;
            if wrong_num == 1:
                return True
        else:
            return False


# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)