//Link: https://leetcode.com/problems/distribute-candies-to-people/ 
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int i = 1;
        int pi = 0;
        while(candies > 0){
            if(candies < i)
                i = candies;
            
            ans[pi%num_people] += i;
            candies -= i;
            ++i;
            ++pi;
        }
        return ans;
    }
};