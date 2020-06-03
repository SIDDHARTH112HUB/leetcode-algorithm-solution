//Link: https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/ 

#define acc(arr) accumulate(arr.begin(), arr.end(), 0)
class Solution {
public:
    vector<vector<double> > pascal;
    int half = 0;
    int sum = 0;
    double getProbability(vector<int>& balls) {
        pascal.resize(49, vector<double>(49));
        pascal[0][0] = 1;
        sum = accumulate(balls.begin(), balls.end(), 0);
        half = sum/2;
        for(int i = 1; i < pascal.size(); ++i) {
            pascal[i][0] = 1;
            for(int j = 1; j <= i; ++j) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        vector<int> leftArr(balls.size()), rightArr(balls.size());
        return dfs(balls, 0, leftArr, rightArr, 0, 0) / combination(balls);
    }
    double combination(vector<int> &nums) {
        int sum = acc(nums);
        double p = 1;
        for(auto n : nums) {
            p *= pascal[sum][n];
            sum -= n;
        }
        return p;
    }
    double dfs(vector<int>& balls, int idx, vector<int>& leftArr, vector<int>& rightArr, int left, int right) {
        if(left > half || right > half) return 0;
        if(idx >= balls.size()) {
            int c1 = 0, c2 = 0;
            for(auto n : leftArr) c1 += n> 0;
            for(auto n : rightArr) c2 += n> 0;
            if(c1 != c2) return 0;
            return combination(leftArr) * combination(rightArr);
        }
        double res = 0;
        for(int i = 0; i <= balls[idx]; ++i) {
            leftArr[idx] = i;
            rightArr[idx] = balls[idx] - i;
            res += dfs(balls, idx + 1, leftArr, rightArr, left + i, right + balls[idx] - i);
        }
        return res;
    }
};