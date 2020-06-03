#Link: https://leetcode.com/problems/valid-palindrome-ii/ 
class Solution(object):
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = len(s)
        idx = -1;
        l1 = list(s);
        l2 = list(s);
        for i in xrange(l):
            if s[i] != s[l-i-1]:
                l1[i] = ""
                l2[l-i-1] = ""
                break
        l1 = "".join(l1)
        l2 = "".join(l2)
        for i in xrange(len(l1)):
            if l1[i] != l1[len(l1)-i-1]:
                break
        else:
            return True
        for i in xrange(len(l2)):
            if l2[i] != l2[len(l2)-i-1]:
                return False
        else:
            return True
        return False