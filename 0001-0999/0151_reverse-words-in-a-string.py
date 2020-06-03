#Link: https://leetcode.com/problems/reverse-words-in-a-string/ 
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        s=s.strip()
        if s=="": return ""
        l = s.split()
        l.reverse()
        return " ".join(l)
        