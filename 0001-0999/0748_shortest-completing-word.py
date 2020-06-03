#Link: https://leetcode.com/problems/shortest-completing-word/ 
class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        letter_dict = {};
        for i in licensePlate:
            i = i.lower();
            if( i>="a" and i <="z"):
                letter_dict[i] = letter_dict.get(i, 0) + 1;
        #print(letter_dict)
        max_len = 1000000000;
        for word in words:
            item = {}
            for c in word:
                item[c.lower()] = item.get(c.lower(), 0)+1
            #print(item)
            for key, cnt in letter_dict.items():
                if( cnt > item.get(key, 0) ):
                    break;
            else:
                if( max_len > len(word)):
                    max_len = len(word)
                    ans = word
        return ans