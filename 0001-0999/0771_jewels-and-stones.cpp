//Link: https://leetcode.com/problems/jewels-and-stones/ 
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> mapS;
        int ans = 0;
        for( char c: S){
            mapS[c]+=1;
        }
        for( char c : J ){
            ans+= mapS[c];
        }
        return ans;
    }
};