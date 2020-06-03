//Link: https://leetcode.com/problems/confusing-number-ii/ 
vector<int> digits = {0, 1, -2, -3, -4, -5, 9, -7, 8, 6};
vector<int> cnt =    {1, 2, 2, 2, 2, 2, 3, 3, 4, 5};
class Solution {
public:

    int confusingNumberII(int N) {
        this->N = N;
        dfs(0);
        return ans;
    }
private:
    int ans = 0;
    vector<int> nums;
    long long N = 0;
    bool check() {
        int s=0,e=nums.size()-1;
        while(s<=e){
            if(nums[s]==6) {
                if(nums[e]!=9)
                    return true;
            }else if(nums[s]==9) {
                if(nums[e]!=6)
                    return true;
            }else if(nums[s]!=nums[e]) return true;
            s++;
            e--;
        }
        return false;
        
    }
    void dfs(long long sum) {
        if(check()){
            ++ans;
        }
        static int ad[5] = {0, 1, 6, 8, 9};
        for(int i = 0; i <= 4; ++i){
            int n = ad[i];
            long long ns = sum * 10 + n;
            if(ns <= N && ns > 0){
                nums.push_back(n);
                dfs(ns);
                nums.pop_back();
            }
        }        
    }
};