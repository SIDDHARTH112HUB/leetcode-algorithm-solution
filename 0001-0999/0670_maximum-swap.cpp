//Link: https://leetcode.com/problems/maximum-swap/ 
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int ans = num;
        for( int i = 0; i<str.size(); i++){
            for( int j = i+1; j<str.size(); j++){
                swap(str[i], str[j]);
                ans = max( stoi(str), ans) ;
                swap(str[i], str[j]);
            }
        }
        return ans;
    }
};