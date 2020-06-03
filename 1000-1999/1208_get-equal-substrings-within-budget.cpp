//Link: https://leetcode.com/problems/get-equal-substrings-within-budget/ 
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int b = 0;
        int src = maxCost;
        //cout<<"begin"<<endl;
        for(int i = 0; i < s.size(); ++i) {
            int diff = abs(s[i] - t[i]);
            if(diff > src) {
                b = i + 1;
                maxCost = src;
                continue;
            }
            if(maxCost >= diff) {
                //cout<<diff<<" "<<maxCost<<" "<<i<<" "<<b<<endl;
                ans = max(ans, i - b + 1);
            }else{
                while( b < i && maxCost < diff){
                    maxCost += abs(s[b] - t[b]);
                    ++b;
                }
                
            }
            maxCost -= diff;
        }
        
        return ans;
    }
};