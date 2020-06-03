//Link: https://leetcode.com/problems/confusing-number/ 
class Solution {
public:
    bool confusingNumber(int N) {
        unordered_map<int, int> m{{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        int rotate = 0;
        int temp = N;
        while (temp != 0) {
            int mod = temp % 10;
            if (!m.count(mod))
                return false;
            rotate = 10 * rotate + m[mod];
            temp /= 10;
        }
        return rotate != N;
    }
};