//Link: https://leetcode.com/problems/shuffle-an-array/ 
class Solution {
public:
    vector<int> origin;
    vector<int> cur;
    Solution(vector<int>& nums) {
        origin = nums;
        cur = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < cur.size(); i++) {
            swap(cur[i], cur[rand() % cur.size()]);
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */