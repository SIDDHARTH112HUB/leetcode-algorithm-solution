#Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/ 
class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        n_s = []
        op = {"*":operator.mul,"-":operator.sub, "+":operator.add, "/":operator.div}
        for i in tokens:
            if i.isdigit()==True or len(i)>1:
                n_s.append(int(i))
            else:
                a2 =n_s.pop()
                a1 = n_s.pop()
                s = int(op[i](a1, a2*1.0))
                n_s.append(s)
        return n_s[0]