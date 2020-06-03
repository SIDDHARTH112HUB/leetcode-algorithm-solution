//Link: https://leetcode.com/problems/maximum-number-of-ones/ 
class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> ones(sideLength* sideLength);
        for(int i = 0; i < width; ++i)
            for(int j = 0; j < height; ++j)
                ++ones[(i % sideLength)*sideLength + (j % sideLength)];
        sort(ones.begin(), ones.end(), greater<int>());
        return accumulate(ones.begin(), ones.begin() + maxOnes, 0);
    }
};