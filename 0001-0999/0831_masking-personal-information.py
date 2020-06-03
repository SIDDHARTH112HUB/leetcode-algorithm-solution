#Link: https://leetcode.com/problems/masking-personal-information/ 
class Solution:
    def maskPII(self, S):
        """
        :type S: str
        :rtype: str
        """
        email_list = S.lower().split("@")
        if( len(email_list)== 2):
            return email_list[0][0]+"*****"+email_list[0][-1]+"@"+email_list[1];
        else:
            cnt = 0;
            dig_str=""
            for c in S:
                if( c >='0' and c<='9'):
                    cnt+=1;
                    dig_str+=c
            phone_list = S.split("-")
            p1 = phone_list[0];
            if( cnt==10 ):
                return "***-***-"+dig_str[-4:]
            else:
                return "+"+"*"*(cnt-10)+"-***-***-" + dig_str[-4:]
            
            