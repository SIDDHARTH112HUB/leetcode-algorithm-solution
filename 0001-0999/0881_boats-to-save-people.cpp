//Link: https://leetcode.com/problems/boats-to-save-people/ 
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int ans = 0, i = 0, j = people.size()-1;
        
        while( i<=j){
            int remain = limit - people[i++];
            if( remain >= people[j]){
                j--;
            }
            ans++;
        }
        return ans;
    }
};