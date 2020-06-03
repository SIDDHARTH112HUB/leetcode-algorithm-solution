#Link: https://leetcode.com/problems/goat-latin/ 
class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        word_list = S.split(" ")
        vowel = {"a":1, "e":1, "i":1, "o":1,"u":1 ,"A":1, "E":1, "I":1, "O":1,"U":1}
        ans_list = []
        for idx, word in enumerate(word_list):
            if vowel.get(word[0]):
                ans_list.append(word + "ma" + "a"*(idx+1))
            else:
                ans_list.append(word[1:] + word[0] +"ma" + "a"*(idx+1))
        return " ".join(ans_list)