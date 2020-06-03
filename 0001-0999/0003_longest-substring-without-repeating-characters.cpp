//Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, 0);
        
        int begin =0, end=0, d=0, counter=0,ans=0, head=0;
        while( end<s.size()){
            if(hash[s[end++]]++ > 0 ) counter++;
            
            while( counter>0){
                ans = max(ans, end-begin-1);
                if( hash[s[begin++]]-->1) counter--;
            }
            
            
        }
        ans = max(ans, end-begin);
        return ans;
    }
};