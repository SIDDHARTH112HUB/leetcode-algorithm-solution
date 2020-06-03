#Link: https://leetcode.com/problems/word-pattern/ 
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        pattern_dict = {}
        str_list = str.split(" ")
        str_dict = {}
        if(len(pattern) != len(str_list) ):
            return False
        for idx, c in enumerate( pattern):
            ps = pattern_dict.get(c)
            if not ps:
                pattern_dict[c] = str_list[idx]
                ps = str_list[idx]
                s = str_dict.get(ps)
                if s:
                    return False
                str_dict[ps] = c
            if ps != str_list[idx]:
                return False
        #print(pattern_dict)
        return True