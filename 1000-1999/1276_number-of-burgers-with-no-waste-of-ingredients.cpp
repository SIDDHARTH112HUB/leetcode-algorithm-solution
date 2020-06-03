//Link: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/ 
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        
        for(int i = 0; i <= cheeseSlices; ++i ) {
            if(i * 4 + (cheeseSlices-i) * 2 == tomatoSlices)
                return {i, cheeseSlices - i};
        }
        return {};
    }
};